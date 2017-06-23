#HELLO CATRIDGEBASE

QT+=widgets
QT+=sql

TEMPLATE = app
TARGET = CatridgeHeaven
INCLUDEPATH += .
CONFIG-=app_bundle

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dbase.cpp

HEADERS += \
    mainwindow.h \
    dbase.h

FORMS += \
    mainwindow.ui
