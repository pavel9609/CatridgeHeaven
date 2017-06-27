<<<<<<< Updated upstream

=======
#HELLO CATRIDGEBASE
>>>>>>> Stashed changes

QT+=widgets
QT+=sql #Без него БД работать не будут

TEMPLATE = app
TARGET = CartridgeHeaven
INCLUDEPATH += .
<<<<<<< Updated upstream
CONFIG-=app_bundle
=======
CONFIG-=app_bundle  #Для работы на mac
>>>>>>> Stashed changes

SOURCES += \
    main.cpp \
    mainwindow.cpp \
<<<<<<< Updated upstream
    dbase.cpp \
    autoritation.cpp
=======
    dbase.cpp
>>>>>>> Stashed changes

HEADERS += \
    mainwindow.h \
    dbase.h \
<<<<<<< Updated upstream
    exception.h \
    autoritation.h

FORMS += \
    mainwindow.ui\
    autoritation.ui

RESOURCES += \
    resources.qrc

=======
    exception.h

FORMS += \
    mainwindow.ui

RESOURCES +=
>>>>>>> Stashed changes
