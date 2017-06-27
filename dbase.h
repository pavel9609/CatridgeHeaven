#ifndef DBASE_H
#define DBASE_H

#include <QtSql>                //Заголовок для БД
#include <QDebug>               //Для дебага

#include "exception.h"          //Для Исключений

class DBase                     //Класс для работы с БД, nuff said
{
public:
    DBase();                                                                            //Стандартный конструктор
    bool insertCartridge(QString brand, QString name, int refull, bool chip, QString chipModel, QString site, QPixmap photo);           //Для вставки катриджа
    bool insertWorker();                                                                //Для вставки работника
    bool insertPrinter();                                                               //Для вставки принтера
    QVector<QVector<QVariant>> selectPrinters();
    QVector<QVector<QVariant>> selectCartridges();
    QVector<QVector<QVariant>> selectCompatibilities();
private:
    QSqlDatabase db;                                                                    //База данных
    QSqlQuery* query;                                                                   //Объект запросов
    bool check;                                                                         //Логическая пересенная для проверок, что бы в if не совать запросы

};

#endif // DBASE_H
