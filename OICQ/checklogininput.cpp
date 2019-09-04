#include "checklogininput.h"
#include "checkregisterinput.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QtSql>


CheckLoginInput::CheckLoginInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckLoginInput)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/image/icon.ico"));
    // TODO: 保留哪个?
    // this->setWindowTitle("Welcome to Oicq2.0");
    this->setWindowTitle("登录");
    tcpSocket = new QTcpSocket;
    QString ip = "10.139.12.133";
    tcpSocket->connectToHost(ip,8010);
    connect(tcpSocket,SIGNAL(connected()),SLOT(connect_success()));
    connect(tcpSocket,SIGNAL(readyRead()),SLOT(onReciveData()));
}

CheckLoginInput::~CheckLoginInput()
{
    delete ui;
}

void CheckLoginInput::on_loginBtn_clicked()
{
    // 判断用户名和密码是否正确
    // 如果错误则弹出警告对话框
    QString user;
    QString pwd;
    user = ui->usrLineEdit->text();//获取用户名
    pwd = ui->pwdLineEdit->text();//获取密码
    if(user == "")
        QMessageBox::warning(this,"","用户名不能为空！");
    else if(pwd == "")
        QMessageBox::warning(this,"","密码不能为空！");
    else
        {
            QString check_str = "1," + user + "," + pwd ;
            QByteArray check = check_str.toLocal8Bit();
            tcpSocket->write(check);
        /*QString S =QString("select * from account where user='%1' and pwd='%2' ").arg(user).arg(pwd);
        QSqlQuery query;
        query.exec(S);
        if (query.first())
        {
            accept();
        }
        else
        {
            QMessageBox::warning(NULL,"Error","用户名或密码错误！！！");
            // 清空内容并定位光标
            ui->usrLineEdit->clear();
            ui->pwdLineEdit->clear();
            ui->usrLineEdit->setFocus();
        }*/
    }
}


void CheckLoginInput::on_registerBtn_clicked()
{
    CheckRegisterInput reg_window;
    tcpSocket->close();
    this->close();
    reg_window.exec();
}

void CheckLoginInput::onReciveData()
{
    QString flag = tcpSocket->readAll();
    if(!QString::localeAwareCompare(flag,"F"))
    {
        usrname = ui->usrLineEdit->text().trimmed();
        accept();
        QMessageBox::warning(NULL,"Error","用户名或密码错误！！！");
        // 清空内容并定位光标
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
    else
    {
        accept();
    }
}

void CheckLoginInput::connect_success()
{
    QMessageBox::information(NULL, "成功", "连接成功！！！", QMessageBox::Yes);

}

