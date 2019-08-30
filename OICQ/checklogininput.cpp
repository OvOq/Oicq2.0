#include "checklogininput.h"
#include "ui_checklogininput.h"
#include <QMessageBox>

CheckLoginInput::CheckLoginInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckLoginInput)
{
    ui->setupUi(this);
}

CheckLoginInput::~CheckLoginInput()
{
    delete ui;
}

void CheckLoginInput::on_loginBtn_clicked()
{
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
    if (ui->usrLineEdit->text().trimmed() == tr("zh") && ui->pwdLineEdit->text() == tr("123456"))//暂时先用zh,123456账号
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);

        // 清空内容并定位光标
               ui->usrLineEdit->clear();
               ui->pwdLineEdit->clear();
               ui->usrLineEdit->setFocus();
    }
}
