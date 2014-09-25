#-------------------------------------------------
#
# Project created by QtCreator 2014-09-25T16:49:29
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SodiumClient
TEMPLATE = app


SOURCES += main.cpp\
        chatwindow.cpp \
    chatclient.cpp

HEADERS  += chatwindow.h \
    chatclient.h

FORMS    += chatwindow.ui
