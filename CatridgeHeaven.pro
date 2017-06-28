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
    autoritation.cpp \
    printwidget.cpp \
    addprintwidget.cpp

HEADERS += \
    mainwindow.h \
    dbase.h \
    exception.h \
    autoritation.h \
    global.h \
    printwidget.h \
    addprintwidget.h \
    printwidget.h

FORMS += \
    mainwindow.ui\
    autoritation.ui \
    printwidget.ui \
    addprintwidget.ui

RESOURCES += \
    resources.qrc


FORMS += \
    mainwindow.ui

