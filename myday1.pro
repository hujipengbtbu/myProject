#-------------------------------------------------
#
# Project created by QtCreator 2017-09-09T12:01:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myday1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    food.cpp \
    gamecontroller.cpp \
    snake.cpp \
    wall.cpp

HEADERS  += mainwindow.h \
    food.h \
    constants.h \
    gamecontroller.h \
    snake.h \
    wall.h

FORMS    += mainwindow.ui
