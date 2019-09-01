#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    chatpage = new ChatWidget;

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
    restoreWinAction = new QAction("back(&R)", this);
    quitAction = new QAction("quit(&Q)", this);

    connect(restoreWinAction, SIGNAL(triggered(bool)), this, SLOT(showNormal()));

    connect(quitAction,SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    trayMenu = new QMenu((QWidget*)QApplication::desktop());
    trayMenu->addAction(restoreWinAction);

    trayMenu->addSeparator();
    trayMenu->addAction(quitAction);
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
    close();
    log_i = new CheckLoginInput(this);
    log_i->show();
}


void MainWindow::on_toolButton_3_clicked()
{
    ui->StackWidget->setCurrentWidget(mainpagewidget);
}

void MainWindow::on_toolButton_4_clicked()
{
    ui->StackWidget->setCurrentWidget(friendpage);
}

void MainWindow::on_toolButton_5_clicked()
{
    ui->StackWidget->setCurrentWidget(chatpage);
}
