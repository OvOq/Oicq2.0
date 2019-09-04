#ifndef CHECKREGISTERINPUT_H
#define CHECKREGISTERINPUT_H

#include <QDialog>
#include <QTcpSocket>
#include <checklogininput.h>

namespace Ui {
class CheckRegisterInput;
}

class CheckRegisterInput : public QDialog
{
    Q_OBJECT

public:
    explicit CheckRegisterInput(QWidget *parent = 0);
    ~CheckRegisterInput();

private slots:
    void on_regBtn_clicked();
    void connect_success();
    void onReciveData();
    void on_backBtn_clicked();
    void reboot();

private:
    Ui::CheckRegisterInput *ui;
    QTcpSocket * tcpsocket;
};

#endif // CHECKREGISTERINPUT_H
