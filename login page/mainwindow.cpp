#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(谁，发出什么信号，谁，执行什么操作)
    connect(this->ui->oicq_login,SIGNAL(clicked(bool)),this,SLOT(LOGIN()));
    connect(this->ui->oicq_cancel,SIGNAL(clicked(bool)),this,SLOT(CANCEL()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LOGIN()
{
    QString name = this->ui->le_account->text();
    QString passwd = this->ui->le_password->text();
    if(name=="Jack"&&passwd=="1234"){
        qDebug()<<"登陆成功";
    }
    else{
        qDebug()<<"登陆失败";
    }
}

void MainWindow::CANCEL()
{
    this->close();
}
