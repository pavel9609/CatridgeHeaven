#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbase.h"
#include"autoritation.h"
#include"printwidget.h"
#include"addprintwidget.h"
#include<QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();
    void on_Printers_clicked();

    void on_Cartriges_clicked();

    void on_Table_clicked();

private:
    Ui::MainWindow *ui;
    PrintWidget* printWidget;
    DBase* dbase;
};

#endif // MAINWINDOW_H
