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
    //ui->verticalLayout->addWidget(auth);
   // this->setFixedSize(470,210);
   /* QPixmap back(":/images/auth.png");
    back=back.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,back);
    this->setPalette(palette);*/
    this->setWindowFlags(Qt::CustomizeWindowHint);
    QFile styleF;
    styleF.setFileName(":/style/style.css");
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
    mBox.setButtonText(QMessageBox::Yes, tr("Да"));
    mBox.setButtonText(QMessageBox::No, tr("Нет"));
    if (mBox.exec()==QMessageBox::Yes)
    qApp->quit();
}
void MainWindow::on_Printers_clicked(bool checked)
{
    qDebug()<<dbase.selectPrinters();
}

void MainWindow::on_Cartriges_clicked()
{
    auto cart = dbase.selectCartridges();
    //Debugenko
    for(auto it = cart.begin();it!=cart.end();it++)
    {
        QDebug debug = qDebug();
        for(auto iit = it->begin();iit!=it->end();iit++)
        {
            debug<<iit;
        }
        debug.~QDebug();
    }
}

void MainWindow::on_Table_clicked()
{
    auto cart = dbase.selectCompatibilities();
    //Debugenko
    for(auto it = cart.begin();it!=cart.end();it++)
    {
        QDebug debug = qDebug();
        for(auto iit = it->begin();iit!=it->end();iit++)
        {
            debug<<iit->toString();
        }
        debug.~QDebug();
    }
}
