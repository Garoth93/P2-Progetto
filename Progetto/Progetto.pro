#-------------------------------------------------
#
# Project created by QtCreator 2019-02-28T09:57:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Progetto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    item.cpp \
    physicalgame.cpp \
    virtualgame.cpp \
    cardgame.cpp \
    controller.cpp \
    menu.cpp \
    negozio.cpp \
    cercapage.cpp \
    modello.cpp \
    listaditem.cpp \
    itemwidget.cpp \
    paginainserimento.cpp \
    paginamodifica.cpp

HEADERS  += mainwindow.h \
    contenitore.h \
    item.h \
    physicalgame.h \
    virtualgame.h \
    cardgame.h \
    controller.h \
    menu.h \
    negozio.h \
    cercapage.h \
    modello.h \
    listaditem.h \
    itemwidget.h \
    paginainserimento.h \
    paginamodifica.h

FORMS    += mainwindow.ui
