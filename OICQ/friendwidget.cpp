#include "friendwidget.h"

friendwidget::friendwidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendwidget)
{
    ui->setupUi(this);
}

friendwidget::~friendwidget()
{
    delete ui;
}
