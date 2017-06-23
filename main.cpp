#include <QApplication>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    qDebug()<<"Hello Git 2";
    qDebug()<<"Skoro obedcss!";
    MainWindow w;
    w.show();
    return app.exec();
}
