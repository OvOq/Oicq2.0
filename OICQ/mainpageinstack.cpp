#include "mainpageinstack.h"
#include "ui_mainpageinstack.h"

MainPageinStack::MainPageinStack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainPageinStack)
{
    ui->setupUi(this);
}

MainPageinStack::~MainPageinStack()
{
    delete ui;
}
