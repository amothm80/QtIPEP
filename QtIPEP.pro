#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T17:40:55
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtIPEP
TEMPLATE = app


SOURCES += \
    src/brightnessdialog.cpp \
    src/imagemanip.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mdichild.cpp \
    src/rgbdialog.cpp



HEADERS  += \
    include/brightnessdialog.h \
    include/imagemanip.h \
    include/mainwindow.h \
    include/mdichild.h \
    include/rgbdialog.h

FORMS    +=   \
        forms/mainwindow.ui \
        forms/rgbdialog.ui \
        forms/brightnessdialog.ui

QMAKE_CXXFLAGS += -std=c++11 -static-libstdc++

DISTFILES +=

INCLUDEPATH += include

RESOURCES += \
    resources.qrc
