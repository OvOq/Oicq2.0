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
#include <QColorDialog>
#include <QTextCharFormat> // 2019/9/2
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
    connect(ui->messageTextEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),
            this,SLOT(currentFormatChanged(const QTextCharFormat))//2019/9/2
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
        ui->messageTextEdit->setFocus();
    }
}
//清空聊天记录  2019/9/2
void Widget::on_clearToolBtn_clicked()
{
    ui->messageBrowser->clear();
}
//退出按钮
void Widget::on_pushButton_2_clicked()
{
    close();
}
//关闭事件
void Widget::closeEvent(QCloseEvent*e)
{
    sendMessage(ParticipantLeft);
    QWidget::closeEvent(e);
}
//多种字体
void Widget::currentFormatChanged(const QTextCharFormat &format)
{
    ui->fontComboBox->setCurrentFont(format.font());
    if(format.fontPointSize()<9)
    {
       ui->sizeComboBox->setCurrentIndex(3);
    }
    else
   {
        ui->sizeComboBox->setCurrentIndex(ui->sizeComboBox
            ->findText(QString::number(format.fontPointSize())));
   }
   ui->boldToolBtn->setChecked(format.font().bold());
   ui->italicToolBtn->setChecked(format.font().italic());
   ui->underlineToolBtn->setChecked(format.font().underline());
   color=format.foreground().color;

}
