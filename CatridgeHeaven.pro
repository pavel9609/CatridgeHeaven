#HELLO CATRIDGEBASE

QT+=widgets
QT+=sql #Без него БД работать не будут

TEMPLATE = app
TARGET = CartridgeHeaven
INCLUDEPATH += .
CONFIG-=app_bundle

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dbase.cpp

HEADERS += \
    mainwindow.h \
    dbase.h \
    exception.h

FORMS += \
    mainwindow.ui
