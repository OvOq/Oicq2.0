/********************************************************************************
** Form generated from reading UI file 'mainpageinstack.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGEINSTACK_H
#define UI_MAINPAGEINSTACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_MainPageinStack
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *MainPageinStack)
    {
        if (MainPageinStack->objectName().isEmpty())
            MainPageinStack->setObjectName(QStringLiteral("MainPageinStack"));
        MainPageinStack->resize(400, 300);
        textEdit = new QTextEdit(MainPageinStack);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 50, 331, 211));

        retranslateUi(MainPageinStack);

        QMetaObject::connectSlotsByName(MainPageinStack);
    } // setupUi

    void retranslateUi(QDialog *MainPageinStack)
    {
        MainPageinStack->setWindowTitle(QApplication::translate("MainPageinStack", "Dialog", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("MainPageinStack", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">waitting for merge</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainPageinStack: public Ui_MainPageinStack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGEINSTACK_H
