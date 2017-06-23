#ifndef DBASE_H
#define DBASE_H

#include <QtSql>    //Заголовок для БД
#include <QDebug>

class DBase
{
public:
    DBase();
private:
    QSqlDatabase db;
};

#endif // DBASE_H
