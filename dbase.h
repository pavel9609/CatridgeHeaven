#ifndef DBASE_H
#define DBASE_H

#include <QtSql>                //Заголовок для БД
#include <QDebug>               //Для дебага
#include <QSqlRelationalTableModel>

#include "exception.h"          //Для Исключений
#include "global.h"             //Глобальные переменные

class DBase                     //Класс для работы с БД, nuff said
{
public:
    bool Enter(QString user,QString password);                                          //Функция входа
    QSqlRelationalTableModel* model();                                                  //Модель
    static DBase* instance();                                                           //Реализация синглтона
private:
    static DBase* _instance;                                                            //Для реализации синглтона
    QSqlDatabase db;                                                                    //База данных
    QSqlQuery* query;                                                                   //Объект запросов
    bool check;                                                                         //Логическая пересенная для проверок, что бы в if не совать запросы
    QSqlRelationalTableModel* _model;                                                   //Модель
    DBase();                                                                            //Стандартный конструктор
    ~DBase();                                                                           //Деструктор

};

#endif // DBASE_H
