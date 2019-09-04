#include "widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QFileDialog>
#include <stdio.h>
#include <QColorDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QtNetwork>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    port=45454;
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));//每当有数据到来时就会触发processPendingDatagrams()这个槽
    connect(this->ui->sendButton,SIGNAL(clicked(bool)),this,SLOT(send()));
    connect(this->ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(cancel()));
    connect(this->ui->saveToolBtn,SIGNAL(clicked(bool)),this,SLOT(toolButton()));

    sendMessage(NewParticipant);
    //以上创建了UDP套接字并进行初始化。sendmessage来广播用户登录信息，并且其函数用来发送各种UDP数据

}

//下面对sendmassage进行定义
void Widget::sendMessage(MessageType type)
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString localHostName =QHostInfo::localHostName();
    QString address =getIP();
    out<<type<<getUserName()<<localHostName;//写入信息类型，用户名，主机名

    switch (type)
    {
        case Message://判断发送的消息是否为空，若为空则警告
            if(ui->messageTextEdit->toPlainText()==""){
                QMessageBox::warning(0,tr("警告"),tr("发送消息不能为空"),QMessageBox::Ok);
                return;
            }
        out<<address<<getMessage();//写入本机Ip和输入的消息文本
        ui->messageBrowser->verticalScrollBar()->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;

        case NewParticipant://新用户加入，则写入IP地址
            out<<address;
            break;

        case ParticipantLeft://用户离开，不操作
            break;

        case  FileName:
            break;

        case Refuse:
            break;

        default:
            break;
    }
    //以上完成了对信息的处理，以下用writeDatagram（）进行广播
    udpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, port);
}

void Widget::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int messageType;
        in>>messageType;//获取信息的数据类型
        QString userName,localHostName,ipAddress,message;
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch (messageType)//对不同的数据类型进行操作
        {
            case Message://普通法聊天消息的操作
                in>>userName>>localHostName>>ipAddress>>message;//依次获取用户名，主机名，IP地址和消息
                ui->messageBrowser->setTextColor(Qt::red);
                ui->messageBrowser->setCurrentFont(QFont("Times New Roman"));
                ui->messageBrowser->append("["+userName+"]"+time);//显示用户名和发消息的时间在左上角的信息浏览器中
                ui->messageBrowser->append(message);//显示所发的消息在左上角的信息浏览器中
                break;

            case NewParticipant://如果消息类型是新用户加入的话
                in>>userName>>localHostName>>ipAddress;//获取用户名，主机名和IP地址信息
                newParticipant(userName,localHostName,time);//进行新用户登陆的处理
                break;

            case ParticipantLeft://若用户退出
                in>>userName>>localHostName;//获取用户名和主机名
                participantLeft(userName,localHostName,time);//进行用户离开的处理
                break;

            case FileName:
                break;

            case Refuse:
                break;

            default:
                break;
        }
    }

}

void Widget::newParticipant(QString userName, QString localHostName, QString ipAddress)//新用户加入的操作
{
    bool isEmpty =ui->userTableWidget->findItems(localHostName,Qt::MatchExactly).isEmpty();//判断用户是否已经加入到用户列表中
    if(isEmpty){//若没有，在消息浏览区显示用户的加入
        QTableWidgetItem *user =new QTableWidgetItem(userName);
        QTableWidgetItem *host =new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip =new QTableWidgetItem(ipAddress);

        ui->userTableWidget->insertRow(0);
        ui->userTableWidget->setItem(0,0,user);
        ui->userTableWidget->setItem(0,1,host);
        ui->userTableWidget->setItem(0,2,ip);

        ui->messageBrowser->setTextColor(Qt::gray);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
        ui->messageBrowser->append(tr("%1在线！").arg(userName));

        ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));//在线人数+1

        sendMessage(NewParticipant);
    }
}

void Widget::participantLeft(QString userName, QString localHostName, QString time)//用户离开
{//将退出的用户信息删除，并进行提示
    int rowNum=ui->userTableWidget->findItems(localHostName,Qt::MatchExactly).first()->row();

    ui->userTableWidget->removeRow(rowNum);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrowser->append(tr("%1于%2离开").arg(userName).arg(time));
    ui->userNumLabel->setText(tr("在线人数：%1").arg(ui->userTableWidget->rowCount()));
}

QString Widget::getIP()//获取ip地址
{
    QList<QHostAddress> List=QNetworkInterface::allAddresses();
    foreach (QHostAddress address, List){
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}

QString Widget::getUserName()//获取用户名
{
    QStringList envVariables;
    envVariables<<"USERNAME.*"<<"USER.*"<<"USERDOMAIN.*"<<"HOSTNAME.*"<<"DOMAINNAME.*";
    QStringList environment= QProcess::systemEnvironment();
    foreach (QString string,envVariables){
        int index=environment.indexOf(QRegExp(string));
        if(index!=-1){
            QStringList stringList=environment.at(index).split('=');//at后可能有问题
            if(stringList.size()==2){
                return stringList.at(1);
                break;
            }
        }
    }
    return "unkown";
}

QString Widget::getMessage()//获取用户输入的消息
{
    QString msg=ui->messageTextEdit->toHtml();//获取消息
    ui->messageTextEdit->clear();//然后清空编辑区
    ui->messageTextEdit->setFocus();
    return msg;
}

void Widget::toolButton()
{
    if(ui->messageBrowser->document()->isEmpty())
    {
        QMessageBox::warning(0,tr("警告"),
                             tr("聊天记录为空，无法保存！"),QMessageBox::Ok);
    }
    else
    {
        // add data base
        QSqlDatabase database;
        if(QSqlDatabase::contains("qt_sql_default_connection"))
        {
            database = QSqlDatabase::database("qt_sql_default_connection");
        }
        else
        {
            database = QSqlDatabase::addDatabase("QSQLITE");
            database.setDatabaseName("MyDataBase.db");
            database.setUserName("My_Name"); // initial name: My_Name
            database.setPassword("000000"); // initial password: 000000
        }
        // put history into database
        if(! database.open())
        {
            qDebug() << "Error: Failed to connect database." << database.lastError();
        }
        else
        {
            QString fileName = QFileDialog::getSaveFileName(this,
            tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt);;All File(*.*)"));

            if(!QString(fileName).isEmpty())
                saveFile(fileName);
        }
     }
}

bool Widget::saveFile(const QString&fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("保存文件"),
           tr("无法保存文件%1:\n%2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out<<ui->messageBrowser->toPlainText();
    return true;
}

//更改字体族
void Widget::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}
//更改字体大小
void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
   ui->messageTextEdit->setFontPointSize(arg1.toDouble());
   ui->messageTextEdit->setFocus();
}
//设置字体加粗、倾斜、下划线和颜色



//加粗
void Widget::on_boldToolBtn_clicked(bool checked)
{
    if(checked)
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    ui->messageTextEdit->setFocus();
}

//倾斜
void Widget::on_italicToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontItalic(checked);
    ui->messageTextEdit->setFocus();
}
//下划线
void Widget::on_underlineToolBtn_clicked(bool checked)
{
    ui->messageTextEdit->setFontUnderline(checked);
    ui->messageTextEdit->setFocus();
}
//颜色
void Widget::on_colorToolBtn_clicked()
{
    color=QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();}
}

void Widget::send()
{
    sendMessage(Message);
}

void Widget::cancel()
{
    this->close();
}

Widget::~Widget()
{
    delete ui;
}
