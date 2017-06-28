#ifndef ADDPRINTWIDGET_H
#define ADDPRINTWIDGET_H
#include <QFileDialog>
#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
namespace Ui {
class AddPrintWidget;
}

class AddPrintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddPrintWidget(QWidget *parent = 0);
    ~AddPrintWidget();

private slots:
    void on_AddPhotoBut_clicked();
    void totalAddButton();
    void backButton();

private:
    Ui::AddPrintWidget *ui;
};

#endif // ADDPRINTWIDGET_H
