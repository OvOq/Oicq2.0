/********************************************************************************
** Form generated from reading UI file 'checklogininput.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKLOGININPUT_H
#define UI_CHECKLOGININPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckLoginInput
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exitBtn;

    void setupUi(QDialog *CheckLoginInput)
    {
        if (CheckLoginInput->objectName().isEmpty())
            CheckLoginInput->setObjectName(QStringLiteral("CheckLoginInput"));
        CheckLoginInput->resize(450, 379);
        CheckLoginInput->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        label = new QLabel(CheckLoginInput);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 80, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(CheckLoginInput);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 140, 81, 21));
        label_2->setFont(font);
        usrLineEdit = new QLineEdit(CheckLoginInput);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));
        usrLineEdit->setGeometry(QRect(180, 80, 221, 31));
        pwdLineEdit = new QLineEdit(CheckLoginInput);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(180, 140, 221, 31));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        horizontalLayoutWidget = new QWidget(CheckLoginInput);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 240, 309, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        loginBtn = new QPushButton(horizontalLayoutWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        loginBtn->setFont(font1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/image/in.png"), QSize(), QIcon::Normal, QIcon::Off);
        loginBtn->setIcon(icon);

        horizontalLayout->addWidget(loginBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        registerBtn = new QPushButton(horizontalLayoutWidget);
        registerBtn->setObjectName(QStringLiteral("registerBtn"));
        registerBtn->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/image/logIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        registerBtn->setIcon(icon1);

        horizontalLayout->addWidget(registerBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        exitBtn = new QPushButton(horizontalLayoutWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setFont(font1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/image/out.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitBtn->setIcon(icon2);

        horizontalLayout->addWidget(exitBtn);


        retranslateUi(CheckLoginInput);
        QObject::connect(exitBtn, SIGNAL(clicked()), CheckLoginInput, SLOT(close()));

        QMetaObject::connectSlotsByName(CheckLoginInput);
    } // setupUi

    void retranslateUi(QDialog *CheckLoginInput)
    {
        CheckLoginInput->setWindowTitle(QApplication::translate("CheckLoginInput", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CheckLoginInput", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("CheckLoginInput", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        usrLineEdit->setPlaceholderText(QApplication::translate("CheckLoginInput", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        pwdLineEdit->setPlaceholderText(QApplication::translate("CheckLoginInput", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("CheckLoginInput", "\347\231\273\345\275\225", Q_NULLPTR));
        registerBtn->setText(QApplication::translate("CheckLoginInput", "\346\263\250\345\206\214", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("CheckLoginInput", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheckLoginInput: public Ui_CheckLoginInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKLOGININPUT_H
