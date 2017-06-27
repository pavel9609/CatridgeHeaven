#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include"autoritation.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    Autoritation auth;
    MainWindow w;
    w.show();
    auth.show();
    return app.exec();
}
