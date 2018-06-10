#-------------------------------------------------
#
# Project created by QtCreator 2018-06-06T14:22:49
#
#-------------------------------------------------

QT       += core gui
QT       += network #网络编程所需要的
QT       += opengl
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uniqueRobot
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/main.cpp \
    ui/mainwindow.cpp \
    src/powerprogressbar.cpp \
    src/netthread.cpp \
    ui/connecterrordialog.cpp \
    ui/connecterrordialog.cpp \
    ui/mainwindow.cpp \
<<<<<<< HEAD
    src/unique.cpp
=======
    src/unique.cpp \
    ui/mymapview.cpp
>>>>>>> newest commit

HEADERS += \
    ui/mainwindow.h \
    src/powerprogressbar.h \
    src/netthread.h \
    ui/connecterrordialog.h \
    ui/connecterrordialog.h \
    ui/mainwindow.h \
<<<<<<< HEAD
    src/unique.h
=======
    src/unique.h \
    ui/mymapview.h
>>>>>>> newest commit

FORMS += \
    ui/mainwindow.ui \
    ui/connecterrordialog.ui

RESOURCES += \
    resource\resource.qrc

