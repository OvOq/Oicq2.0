#ifndef MAINPAGEINSTACK_H
#define MAINPAGEINSTACK_H

#include <QDialog>

namespace Ui {
class MainPageinStack;
}

class MainPageinStack : public QDialog
{
    Q_OBJECT

public:
    explicit MainPageinStack(QWidget *parent = 0);
    ~MainPageinStack();

private:
    Ui::MainPageinStack *ui;
};

#endif // MAINPAGEINSTACK_H
