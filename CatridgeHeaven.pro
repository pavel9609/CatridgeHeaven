QT+=widgets
QT+=sql #Без него БД работать не будут

TEMPLATE = app
TARGET = CartridgeHeaven
INCLUDEPATH += .
CONFIG-=app_bundle  #Для работы на mac

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    dbase.cpp \
    autoritation.cpp

HEADERS += \
    mainwindow.h \
    dbase.h \
    exception.h \
    autoritation.h

FORMS += \
    mainwindow.ui\
    autoritation.ui

RESOURCES += \
    resources.qrc


FORMS += \
    mainwindow.ui

RESOURCES +=
