#ifndef AUTORITATION_H
#define AUTORITATION_H

#include <QWidget>
#include<QPixmap>
#include<QEvent>
#include<QMouseEvent>
#include<QPoint>
#include<QFile>


namespace Ui {
class Autoritation;
}

class Autoritation : public QWidget
{
    Q_OBJECT

public:
    explicit Autoritation(QWidget *parent = 0);
    ~Autoritation();

public slots:
    void signIn();

private:
    Ui::Autoritation *ui;
    QWidget* my_widget;
    bool moving;
    QPoint lastPoint;
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // AUTORITATION_H
