#-------------------------------------------------
#
# Project created by QtCreator 2019-08-29T15:42:30
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OICQ
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    checklogininput.cpp \
    mainpageinstack.cpp \
    friendwidget.cpp \
    widget.cpp \
    tcpserver.cpp \
    tcpclient.cpp

HEADERS += \
        mainwindow.h \
    checklogininput.h \
    mainpageinstack.h \
    friendwidget.h \
    widget.h \
    tcpserver.h \
    tcpclient.h

FORMS += \
        mainwindow.ui \
    checklogininput.ui \
    mainpageinstack.ui \
    friendwidget.ui \
    widget.ui \
    tcpserver.ui \
    tcpclient.ui

RESOURCES += \
    image.qrc \
    image_index.qrc \
    test.qrc

DISTFILES +=
