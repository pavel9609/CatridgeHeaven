#include "dbase.h"

DBase::DBase()
{
    try //Чтобы облегчить сброс, если что-то не так
    {
        db = QSqlDatabase::addDatabase("QSQLITE");    //Добавляем базу, метод может быть только статических
        if (!db.isValid()) throw Exception("Valid");
        db.setDatabaseName(QDir::currentPath()+"/Cartridge.sqlite");
        if (!db.open()) throw Exception("Open");    //Открываем и кричим, если что-то не так.
        query = new QSqlQuery(db);  //Связываем запрос с базой
        if (!createTables())  throw Exception("Create table error");
    }
    catch(Exception e)
    {
        if (db.lastError().text() != " ") qDebug()<<e.Error()<<db.lastError().text();
        else qDebug()<<e.Error()<<query->lastError().text(); //Ошибка, которую мы указали и ошибка базы данных
    }
}
bool DBase::createTables()
{
    try //Чтобы облегчить сброс, если что-то не так
    {
        //Картриджи
        check = query->exec("CREATE TABLE IF NOT EXISTS cartridges(" //Создаём таблицу катриджей
                    "id INTEGER, "
                    "brand VARCHAR(50) NOT NULL,"
                    "name VARCHAR(50) NOT NULL, "
                    "refull INT NOT NULL,"
                    "chip BOOLEAN NOT NULL,  "
                    "PRIMARY KEY (id));");
        if (!check) throw Exception("Create Table cartridges"); //Кричим, если табличка не создается
        //Принтеры
        check = query->exec("CREATE TABLE IF NOT EXISTS printers(" //Создаём таблицу принтеров
                    "id INTEGER, "
                    "name VARCHAR(50) NOT NULL, "
                    "coloured BOOLEAN NOT NULL,  "
                    "PRIMARY KEY (id));");
        if (!check) throw Exception("Create Table printers");
        //Совместимости
        check = query->exec("CREATE TABLE IF NOT EXISTS compatibility(" //Создаём таблицу принтеров
                    "cartridgeID INT NOT NULL, "
                    "printerID INT NOT NULL,  "
                    "PRIMARY KEY (cartridgeID,printerID),"
                    "FOREIGN KEY(cartridgeID) REFERENCES cartridges(id),"
                    "FOREIGN KEY(printerID) REFERENCES printers(id)"
                    ");");
        if (!check) throw Exception("Create Table compatibility");
        //Работники
        check = query->exec("CREATE TABLE IF NOT EXISTS  workers(" //Создаём таблицу работников
                    "id INTEGER, "
                    "name VARCHAR(50) NOT NULL, "
                    "surname VARCHAR(50) NOT NULL,  "
                    "username VARCHAR(50) NOT NULL,  "
                    "password VARCHAR(50) NOT NULL,  "
                    "position VARCHAR(50) NOT NULL,  "
                    "PRIMARY KEY (id));");
        if (!check) throw Exception("Create Table workers");
        //Заявки
        check = query->exec("CREATE TABLE IF NOT EXISTS  applications(" //Создаём таблицу работников
                    "id INTEGER, "
                    "cartridgeID INT NOT NULL, "
                    "workerID INT NOT NULL, "
                    "victimName VARCHAR(50) NOT NULL, "
                    "victimSurname VARCHAR(50) NOT NULL, "
                    "victimPatron VARCHAR(50) NOT NULL, "
                    "comment VARCHAR(500) NOT NULL, "
                    "applicationTime DATETIME NOT NULL, "
                    "PRIMARY KEY (id),"
                    "FOREIGN KEY(cartridgeID) REFERENCES cartridges(id),"
                    "FOREIGN KEY(workerID) REFERENCES workers(id)"
                    ");");
        if (!check) throw Exception("Create Table applications");
    }
    catch(Exception e)
    {
        qDebug()<<e.Error()<<query->lastError().text(); //Ошибка, которую мы указали и ошибка базы данных
        return false;
    }
    return true;
}
