#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(470,210);
    QPixmap back("C:\\Users\\Var\\Desktop\\auth.png");
    back=back.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,back);
    this->setPalette(palette);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    /*QPixmap pixmap("C:\\Users\\Var\\Desktop\\RosAtom_logo_rus.jpg");
    pixmap.scaled(ui->label->size().width(),ui->label->size().height(),Qt::IgnoreAspectRatio,Qt::FastTransformation);
    ui->label->setPixmap(pixmap);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Printers_clicked(bool checked)
{
    qDebug()<<dbase.selectPrinters();
}

void MainWindow::on_Cartriges_clicked()
{
    qDebug()<<dbase.selectCartridges();
}
