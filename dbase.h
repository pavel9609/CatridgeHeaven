#ifndef DBASE_H
#define DBASE_H

#include <QtSql>            //Заголовок для БД
#include <QDebug>           //Для дебага

#include "exception.h"      //Для Исключений

class DBase                 //Класс для работы с БД, nuff said
{
public:
    DBase();                //Стандартный конструктор
private:
    QSqlDatabase db;        //База данных
    QSqlQuery* query;       //Объект запросов
    bool check;             //Логическая пересенная для проверок, что бы в if не совать запросы
    bool createTables();    //Чтобы вынести создание таблиц в отдельную функцию иначе в конструкторе ад какой-то
};

#endif // DBASE_H
