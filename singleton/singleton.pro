QT += core
QT -= gui

TARGET = singleton
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    singleton.cpp

HEADERS += \
    singleton.h \
    mythread.h

