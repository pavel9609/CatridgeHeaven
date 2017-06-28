#include "addprintwidget.h"
#include "ui_addprintwidget.h"

AddPrintWidget::AddPrintWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPrintWidget)
{
    ui->setupUi(this);
    ui->TypeComboBox->addItem("Черно-белый");
    ui->TypeComboBox->addItem("Цветной");
    ui->PhotoTextEdit;
    connect(ui->AddBut, SIGNAL(clicked(bool)), this, SLOT(totalAddButton()));
    connect(ui->BackBut, SIGNAL(clicked(bool)), this, SLOT(backButton()));
}

AddPrintWidget::~AddPrintWidget()
{
    delete ui;
}

void AddPrintWidget::totalAddButton()
{
    //code for add record to DB
    this->close();
}

void AddPrintWidget::backButton()
{
    this->close();
}

void AddPrintWidget::on_AddPhotoBut_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        //QTextStream in(&file);
        ui->PhotoTextEdit->setText(fileName);
        //file.close();

}
}
