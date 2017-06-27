#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include <QTranslator>
int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QTranslator translator;
    translator.load("qt_ru.qm");
    app.installTranslator(&translator);
    MainWindow w;
    w.show();
    return app.exec();
}
