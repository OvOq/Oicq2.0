#include "tcpserver.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QtSql>
#include <QString>

//构造函数建立窗口
TcpServer::TcpServer(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("TCP Server"));
    ContentListWidget = new QListWidget;
    PortLabel = new QLabel(tr("端口："));
    PortLineEdit = new QLineEdit;
    CreateBtn = new QPushButton(tr("创建聊天室"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,2);
    mainLayout->addWidget(PortLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,2,0,1,2);
    port=8010;
    PortLineEdit->setText(QString::number(port));
    connect(CreateBtn,SIGNAL(clicked()),this,SLOT(slotCreateServer()));

}

//建立服务端
void TcpServer::slotCreateServer()
{
    server = new Server(this,port);				//创建一个Server对象
    connect(server,SIGNAL(updateServer(QString,int)),this,
            SLOT(updateServer(QString,int)));
    connect(this,SIGNAL(check_result(QString)),server,SLOT(check_result(QString)));
    CreateBtn->setEnabled(false);
}

//服务端消息显示
void TcpServer::updateServer(QString msg,int length)
{

    QString flag,user,pwd,result;
    flag = msg.section(',',0,0);
    user = msg.section(',',1,1);
    pwd = msg.section(',',2,2);
    //登陆
    if(flag.toInt()==1)
    {
        QString S =QString("select * from account where user='%1' and pwd='%2' ").arg(user).arg(pwd);
        QSqlQuery query;
        query.exec(S);
        if (query.first())
            result = "T";
        else
            result = "F";

    }
    //注册
    else
    {

        QString i = QString("insert into account values('%1','%2');").arg(user).arg(pwd);
        QString S =QString("select * from account where user='%1' ").arg(user);
        QSqlQuery query;
        if(query.exec(S)&&query.first())
        {
              result = "S";
        }
        else if (query.exec(i))
        {
              result = "R";
        }
        else
        {
              result = "E";

        }
    }
    ContentListWidget->addItem(msg.left(length));


    emit check_result(result);
}

//
TcpServer::~TcpServer()
{

}
