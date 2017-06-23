#HELLO CATRIDGEBASE

QT+=widgets

TEMPLATE = app
TARGET = CatridgeHeaven
INCLUDEPATH += .
CONFIG-=app_bundle

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui
