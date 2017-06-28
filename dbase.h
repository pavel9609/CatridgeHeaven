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

    bool insertCartridge(QString brand, QString name, int refull,
                  bool chip, QString chipModel, QString site, QPixmap photo);           //Для вставки катриджа
    bool insertWorker();                                                                //Для вставки работника
    bool insertPrinter();                                                               //Для вставки принтера
    QVector<QVector<QVariant>> selectPrinters();                                        //Выбираем принтеры
    QVector<QVector<QVariant>> selectCartridges();                                      //Выбираем картриджи
    QVector<QVector<QVariant> > selectCompatibilities();                                //Выбираем связи
    bool Enter(QString user,QString password);                                          //Функция входа
    QSqlRelationalTableModel* model();
    static DBase* instance();
private:
    static DBase* _instance;
    QSqlDatabase db;                                                                    //База данных
    QSqlQuery* query;                                                                   //Объект запросов
    bool check;                                                                         //Логическая пересенная для проверок, что бы в if не совать запросы
    QSqlRelationalTableModel* _model;                                                   //Модель
    DBase();                                                                            //Стандартный конструктор
    ~DBase();                                                                           //Деструктор

};

#endif // DBASE_H
