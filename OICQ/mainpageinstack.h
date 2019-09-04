#ifndef MAINPAGEINSTACK_H
#define MAINPAGEINSTACK_H
#include <QTimer>
#include <QTime>
#include <qtimer.h>
#include <qmath.h>
#include <QRectF>
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

    void paintEvent(QPaintEvent *event);
    QRectF textRectF(double radius, int pointsize, double angle);

private:
    Ui::MainPageinStack *ui;
};

#endif // MAINPAGEINSTACK_H
