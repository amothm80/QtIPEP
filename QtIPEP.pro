#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T17:40:55
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtIPEP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagemanip.cpp \
    mdichild.cpp


HEADERS  += mainwindow.h \
    imagemanip.h \
    mdichild.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11 -static-libstdc++
