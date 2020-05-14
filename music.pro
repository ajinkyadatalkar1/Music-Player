#-------------------------------------------------
#
# Project created by QtCreator 2017-07-11T20:18:13
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = music
TEMPLATE = app


SOURCES += main.cpp \
    body.cpp \
    layout.cpp \
    controls.cpp \
    player.cpp

HEADERS  += \
    body.h \
    layout.h \
    controls.h \
    player.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

