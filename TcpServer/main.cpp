#include "tcpserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpServer w;

    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//添加数据库驱动
    db.setHostName("localhost");//本地
    db.setDatabaseName("ID_Database");//设置数据库名
    db.setUserName("root");//账号
    db.setPassword("123456");//密码
    //判断数据库是否打开成功
    if (db.open())
    {
        w.show();
    }
    else
    {
        QMessageBox::warning(NULL,"error","数据库连接失败");
        return 0;
    }

    //以下是在数据库中创建账号密码表account
    QSqlQuery query;
    query.exec("create table account (user varchar, pwd varchar)");

    return a.exec();
}
