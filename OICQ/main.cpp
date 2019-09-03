#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QSqlQuery>
#include "checklogininput.h"
#include "checkregisterinput.h"
#include <QTcpSocket>
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    CheckLoginInput dlg;
    w.setWindowTitle("欢迎来到OICQ2.0");//设置窗体标题




    /*以下是数据库*/
        /*qDebug() << "Availiable drivers:";
        QStringList drivers = QSqlDatabase::drivers();
        foreach(QString driver, drivers)
            qDebug() << driver;*/

    //连接数据库
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//添加数据库驱动
    db.setHostName("localhost");//本地
    db.setDatabaseName("ID_Database");//设置数据库名
    db.setUserName("root");//账号
    db.setPassword("123456");//密码*/

    //判断数据库是否打开成功
    /*if (db.open())
    {
        dlg.show();
    }
    else
    {
        QMessageBox::warning(NULL,"error","数据库连接失败");
        return 0;
    }*/

    /*以下是在数据库中创建账号密码表account*/
    /*QSqlQuery query;
    query.exec("create table account (user varchar, pwd varchar)");*/

    /*以下是登录页面*/
    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();//展示MainWindow
        return a.exec();
    }
    else
        return 0;

}


