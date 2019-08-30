#ifndef CHECKLOGININPUT_H
#define CHECKLOGININPUT_H

#include <QDialog>

namespace Ui {
class CheckLoginInput;
}

class CheckLoginInput : public QDialog
{
    Q_OBJECT

public:
    explicit CheckLoginInput(QWidget *parent = 0);
    ~CheckLoginInput();

private slots:
    void on_loginBtn_clicked();

private:
    Ui::CheckLoginInput *ui;
};

#endif // CHECKLOGININPUT_H
