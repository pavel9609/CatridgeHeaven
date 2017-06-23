#include "dbase.h"

DBase::DBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE","CartridgeDB");    //Добавляем базу, метод может быть только статических
    if (db.isValid()) qDebug()<<"woo-hoo";
    else qDebug()<<db.lastError().text();  //Если ошибка
    //sdfgvhb
}
