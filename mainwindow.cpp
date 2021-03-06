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
    printWidget = new PrintWidget;
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

    connect(ui->Printers, SIGNAL(clicked(bool)),this,SLOT(on_Printers_clicked()));

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
void MainWindow::on_Printers_clicked()
{
    ui->verticalLayout->addWidget(printWidget);
}

void MainWindow::on_Cartriges_clicked()
{
}

void MainWindow::on_Table_clicked()
{
}
