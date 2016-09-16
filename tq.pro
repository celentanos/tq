#-------------------------------------------------
#
# Project created by QtCreator 2016-08-17T14:13:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tq
TEMPLATE = app

DESTDIR = $$PWD/bin

SOURCES += main.cpp\
        mainwindow.cpp \
    log.cpp \
    char_property.cpp \
    widget_property.cpp \
    widget_properties.cpp \
    char_skill.cpp \
    char_properties.cpp \
    char_skills.cpp \
    character.cpp

HEADERS  += mainwindow.h \
    log.h \
    char_property.h \
    widget_property.h \
    widget_properties.h \
    char_skill.h \
    char_properties.h \
    char_skills.h \
    character.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md
