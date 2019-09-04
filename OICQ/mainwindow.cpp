#include "mainwindow.h"
#include "stdio.h"
#include "friendwidget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QFile>
#include <QFileDialog>
#include <QColorDialog>
#include <QDialog>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint), // hind the default window button
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Oicq2.0");
    this->setWindowIcon(QIcon(":/new/prefix1/image/icon.ico"));


    createMenu();

    if(!QSystemTrayIcon::isSystemTrayAvailable())
    {
        return;
    }

    //change window button, add icon
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/new/prefix1/image/icon.ico"));
    trayIcon->setToolTip("Calculator");
    trayIcon->showMessage("test","test merge",QSystemTrayIcon::Information,10000);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();

    //after logout,back to log in
    connect(ui->toolButton_6, SIGNAL(clicked(bool)), this, SLOT(condButtonPressed()));

    //stack window init
    mainpagewidget = new MainPageinStack;
    friendpage = new friendwidget;
    chatpage = new Widget;

    //toolButton stylesheet
    ui->toolButton_3->setCheckable(true);
    ui->toolButton_3->setChecked(true);
    ui->toolButton_3->setAutoExclusive(true);
    ui->toolButton_3->setStyleSheet("QToolButton{background-color:#86b8e9; outline:none;border:3px solid white; border-radius:3px}"
                                    "QToolButton:hover{background-color:#a6caf2}"
                                    "QToolButton:pressed{background-color:#a6caf2}");
    ui->toolButton_4->setCheckable(true);
    ui->toolButton_4->setChecked(true);
    ui->toolButton_4->setAutoExclusive(true);
    ui->toolButton_4->setStyleSheet("QToolButton{background-color:#86b8e9; outline:none;border:3px solid white; border-radius:3px}"
                                    "QToolButton:hover{background-color:#a6caf2}"
                                    "QToolButton:pressed{background-color:#a6caf2}");
    ui->toolButton_5->setCheckable(true);
    ui->toolButton_5->setChecked(true);
    ui->toolButton_5->setAutoExclusive(true);
    ui->toolButton_5->setStyleSheet("QToolButton{background-color:#86b8e9; outline:none;border:3px solid white; border-radius:3px}"
                                    "QToolButton:hover{background-color:#a6caf2}"
                                    "QToolButton:pressed{background-color:#a6caf2}");
    ui->toolButton_6->setCheckable(true);
    ui->toolButton_6->setChecked(true);
    ui->toolButton_6->setAutoExclusive(true);
    ui->toolButton_6->setStyleSheet("QToolButton{background-color:#86b8e9; outline:none;border:3px solid white; border-radius:3px}"
                                    "QToolButton:hover{background-color:#a6caf2}"
                                    "QToolButton:pressed{background-color:#a6caf2}");

    ui->StackWidget->addWidget(mainpagewidget);
    ui->StackWidget->addWidget(friendpage);
    ui->StackWidget->addWidget(chatpage);

    ui->gridLayout->addWidget(ui->StackWidget);
    ui->gridLayout->addWidget(ui->StackWidget);
    ui->gridLayout->addWidget(ui->StackWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenu()
{
    restoreWinAction = new QAction("open(&R)", this);
    quitAction = new QAction("quit(&Q)", this);

    connect(restoreWinAction, SIGNAL(triggered(bool)), this, SLOT(showNormal()));

    connect(quitAction,SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    trayMenu = new QMenu((QWidget*)QApplication::desktop());
    trayMenu->addAction(restoreWinAction);

    trayMenu->addSeparator();
    trayMenu->addAction(quitAction);
}

void MainWindow::reboot()
{
    QString program = QApplication::applicationFilePath();
    QStringList arguments = QApplication::arguments();
    QString workingDirectory = QDir::currentPath();
    QProcess::startDetached(program, arguments, workingDirectory);
    QApplication::exit();
}

void QWidget::changeEvent(QEvent *e)
{
    if((e->type() == QEvent::WindowStateChange)&&this->isMinimized())
    {
        this->hide();
    }
}

void MainWindow::on_toolButton_2_clicked()
{
    close();
}

void MainWindow::on_toolButton_clicked()
{
    hide();
}

void MainWindow::condButtonPressed()
{
    reboot();
}


void MainWindow::on_toolButton_3_clicked()
{
    ui->StackWidget->setCurrentWidget(mainpagewidget);
    ui->toolButton_3->setDown(true);
    ui->toolButton_4->setDown(false);
    ui->toolButton_5->setDown(false);
    ui->toolButton_4->setDown(false);
}

void MainWindow::on_toolButton_4_clicked()
{
    ui->toolButton_3->setDown(false);
    ui->toolButton_4->setDown(true);
    ui->toolButton_5->setDown(false);
    ui->toolButton_4->setDown(false);
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("保存聊天记录"), tr("聊天记录"),tr("文本(*.txt);;All File(*.*)"));

    if(!fileName.isNull())
    {
        QFile file(fileName);
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::warning(this, tr("Error"), tr("read file error:&1").arg(file.errorString()));

            return;
        }
        QTextStream in(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);

        friendpage = new friendwidget(this);
        friendpage ->setModal(false);


        friendpage->ui->textEdit->setPlainText(in.readAll());

        QApplication::restoreOverrideCursor();
        friendpage->show();
        ui->StackWidget->setCurrentWidget(friendpage);
    }
    else
    {
        qDebug()<<"quit";
    }
    //ui->StackWidget->setCurrentWidget(friendpage);
}

void MainWindow::on_toolButton_5_clicked()
{
    ui->toolButton_3->setDown(false);
    ui->toolButton_4->setDown(false);
    ui->toolButton_5->setDown(true);
    ui->toolButton_4->setDown(false);
    ui->StackWidget->setCurrentWidget(chatpage);
}
