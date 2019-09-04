#include "checkregisterinput.h"
#include "mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QtSql>
#include <QDir>
#include <QProcess>

CheckRegisterInput::CheckRegisterInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckRegisterInput)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    tcpsocket = new QTcpSocket();
    QString ip = "10.139.12.133";
    tcpsocket->connectToHost(ip,8010);
    connect(tcpsocket,SIGNAL(connected()),SLOT(connect_success()));
    connect(tcpsocket,SIGNAL(readyRead()),SLOT(onReciveData()));
}


CheckRegisterInput::~CheckRegisterInput()
{
    delete ui;
}

void CheckRegisterInput::on_regBtn_clicked()
{
    QString user;
    QString pwd;
    user = ui->reg_user_lineEdit->text();
    pwd = ui->reg_pwd_lineEdit->text();

    if(user == "")
    {
        QMessageBox::warning(this,"","用户名不能为空！");
    }
    else if(pwd == "")
    {
        QMessageBox::warning(this,"","密码不能为空！");
    }
    else
    {

        QString check_str = "2," + user + "," + pwd ;
        QByteArray check = check_str.toLocal8Bit();
        tcpsocket->write(check);
        /*QString i = QString("insert into account values('%1','%2');").arg(user).arg(pwd);
        QString S =QString("select * from account where user='%1' ").arg(user);
        QSqlQuery query;
        if(query.exec(i))
        {
            QMessageBox::information(NULL, "注册成功", "注册成功！！！", QMessageBox::Yes);
            this->close();
        }
        else if(query.exec(S)&&query.first())
            QMessageBox::warning(NULL,"Error","用户名重复！！！");
        else
            QMessageBox::warning(NULL,"Error","注册失败，请重试！！！");*/
    }

}

void CheckRegisterInput::onReciveData()
{
    QString flag = tcpsocket->readAll();
    if(!QString::localeAwareCompare(flag,"E"))
    {
        QMessageBox::warning(NULL,"Error","注册失败，请重试！！！");

    }
    else if(!QString::localeAwareCompare(flag,"S"))
    {
        QMessageBox::warning(NULL,"Error","用户名重复！！！");

    }
    else if(!QString::localeAwareCompare(flag,"R"))
    {
        QMessageBox::information(NULL, "注册成功", "注册成功！！！", QMessageBox::Yes);
        tcpsocket->close();
    }
}

void CheckRegisterInput::connect_success()
{
    QMessageBox::information(NULL, "成功", "连接成功！！！", QMessageBox::Yes);
}
void CheckRegisterInput::reboot()
{
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
}

void CheckRegisterInput::on_backBtn_clicked()
{
    /* CheckLoginInput log_window;
    tcpsocket->close();
    this->close();
    log_window.exec();*/
    // reboot
    reboot();
}
