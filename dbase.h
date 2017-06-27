#ifndef DBASE_H
#define DBASE_H

#include <QtSql>                //Заголовок для БД
#include <QDebug>               //Для дебага
#include <QSqlRelationalTableModel>
#include "exception.h"          //Для Исключений
#include "global.h"

class DBase                     //Класс для работы с БД, nuff said
{
public:
    DBase();                                                                            //Стандартный конструктор
    ~DBase();                                                                           //Деструктор
    bool insertCartridge(QString brand, QString name, int refull,
                  bool chip, QString chipModel, QString site, QPixmap photo);           //Для вставки катриджа
    bool insertWorker();                                                                //Для вставки работника
    bool insertPrinter();                                                               //Для вставки принтера
    QVector<QVector<QVariant>> selectPrinters();                                        //Выбираем принтеры
    QVector<QVector<QVariant>> selectCartridges();                                      //Выбираем картриджи
    QVector<QVector<QVariant>> selectCompatibilities();                                 //Выбираем связи
    bool Enter(QString user,QString password);                                          //Функция входа

private:
    QSqlDatabase db;                                                                    //База данных
    QSqlQuery* query;                                                                   //Объект запросов
    bool check;                                                                         //Логическая пересенная для проверок, что бы в if не совать запросы
    QSqlRelationalTableModel* model;

};

#endif // DBASE_H
