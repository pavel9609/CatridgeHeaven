#ifndef PRINTWIDGET_H
#define PRINTWIDGET_H

#include <QWidget>
#include<addprintwidget.h>

namespace Ui {
class PrintWidget;
}

class PrintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PrintWidget(QWidget *parent = 0);
    ~PrintWidget();
     AddPrintWidget* addPrintWidget;

public slots:
    void addButton();

private:
    Ui::PrintWidget *ui;

};

#endif // PRINTWIDGET_H
