#include "autoritation.h"
#include "ui_autoritation.h"

Autoritation::Autoritation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Autoritation)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/images/auth.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setWindowFlags(Qt::CustomizeWindowHint);

    QFile styleF;
    styleF.setFileName(":/style/style.css");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();

    this->setStyleSheet(qssStr);

    ui->loginLine->setPlaceholderText("Логин");
    ui->passwordLine->setPlaceholderText("Пароль");
    ui->passwordLine->setEchoMode(QLineEdit::Password);
    ui->errPic->hide();
    ui->errorLabel->hide();

    connect(ui->exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->signInButton, SIGNAL(clicked(bool)), this, SLOT(signIn()));
    db = DBase::instance();

}

Autoritation::~Autoritation()
{
    delete ui;
}

void Autoritation::mouseMoveEvent(QMouseEvent *e)
{
    if((e->buttons() && Qt::LeftButton))
    move(e->globalX()-lastPoint.x(),e->globalY()-lastPoint.y());
}

void Autoritation::mousePressEvent(QMouseEvent *e)
{
    QRect p = this->geometry();
    if(e->button() == Qt::LeftButton)
    {
        lastPoint = e->pos(); moving = true;
    }
}

void Autoritation::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton && moving)
    {
        moving = false;
    }
}

void Autoritation::signIn()
{
    bool check = db->Enter(ui->loginLine->text(),ui->passwordLine->text());
    if (check){
        this->hide();
        MainWindow* window = new MainWindow;
        window->show();
    }
    else
    {
        ui->errPic->show();
        ui->errorLabel->show();
    }


}
