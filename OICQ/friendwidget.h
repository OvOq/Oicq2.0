#ifndef FRIENDWIDGET_H
#define FRIENDWIDGET_H

#include <QDialog>

namespace Ui {
class friendwidget;
}

class friendwidget : public QDialog
{
    Q_OBJECT

public:
    explicit friendwidget(QWidget *parent = 0);
    ~friendwidget();

private:
    Ui::friendwidget *ui;
};

#endif // FRIENDWIDGET_H
