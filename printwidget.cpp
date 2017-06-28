#include "printwidget.h"
#include "ui_printwidget.h"

PrintWidget::PrintWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintWidget)
{
    ui->setupUi(this);
    addPrintWidget = new AddPrintWidget;
    connect(ui->AddPrinterBut, SIGNAL(clicked(bool)),this, SLOT(addButton()));
}

void PrintWidget::addButton()
{
    addPrintWidget->show();
}

PrintWidget::~PrintWidget()
{
    delete ui;
}
