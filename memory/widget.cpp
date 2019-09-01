#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QFileDialog>
#include <stdio.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    port=45454;
    udpSocket->bind(port,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    connect(ui->saveToolBtn,SIGNAL(clicked(bool)),this,SLOT(toolButton()));
    //sendMessage(NewParticipant);
}

Widget::~Widget()
{
    delete ui;
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
        QString fileName = QFileDialog::getSaveFileName(this,
        tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt);;All File(*.*)"));

        if(!QString (fileName).isEmpty())
            saveFile(fileName);
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
