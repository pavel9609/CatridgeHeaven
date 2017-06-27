#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QTranslator>

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
    QFile styleF;
    styleF.setFileName("C:\\Users\\Var\\Desktop\\style.css");
    styleF.open(QFile::ReadOnly);
    QString qssStr=styleF.readAll();
    this->setStyleSheet(qssStr);
    /*QPixmap pixmap("C:\\Users\\Var\\Desktop\\RosAtom_logo_rus.jpg");
    pixmap.scaled(ui->label->size().width(),ui->label->size().height(),Qt::IgnoreAspectRatio,Qt::FastTransformation);
    ui->label->setPixmap(pixmap);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("CartridgeHeaven"));
    mBox.setText(tr("Вы действительно хотите выйти?"));
    mBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    if (mBox.exec()==QMessageBox::Yes)
    qApp->quit();
}
