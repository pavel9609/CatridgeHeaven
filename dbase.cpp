#include "dbase.h"

DBase* DBase::_instance = 0;

DBase::DBase()
{
    try     { //Чтобы облегчить сброс, если что-то не так
        db = QSqlDatabase::addDatabase("QSQLITE");    //Добавляем базу, метод может быть только статических
        if (!db.isValid()) throw Exception("Valid");    //Если что-то не получается
        db.setDatabaseName(QDir::currentPath()+"/Cartridge.sqlite");    //Отправляем к исполняемому файлу
        if (!db.open()) throw Exception("Open");    //Открываем и кричим, если что-то не так.
        query = new QSqlQuery(db);  //Связываем запрос с базой
        _model = new QSqlRelationalTableModel(0,db);
    }
    catch(Exception e)  {
        if (db.lastError().text() != " ") qDebug()<<e.Error()<<db.lastError().text();
        else qDebug()<<e.Error()<<query->lastError().text(); //Ошибка, которую мы указали и ошибка базы данных
    }
}
bool DBase::Enter(QString user, QString password)
{
    check = query->prepare("SELECT password FROM Workers WHERE UserName=:name");   //Готовим запрос
    if (!check) throw ("Enter prepare");
    query->bindValue(":name",user); //Вставляем имя пользователя
    check = query->exec();  //Выполняем
    if(!check) throw ("Enter exec");    //Если что-то не выполнилось
    if(query->next())   {   //Пользователь найден
        if(query->value(0).toString() == password)  {
            userName=user;
            check = query->prepare("SELECT Privilege FROM Workers WHERE UserName=:name");
            if(!check) throw ("Get Privelegion exec");
            query->bindValue(":name",user); //Вставляем имя пользователя
            check = query->exec();  //Выполняем
            if(!check) throw ("Get Privelegion exec");
            if(query->next()) userPrivilegions = query->value(0).toLongLong();
            return true;
        }   else false;
    }   else return false; //Пользователь не найден
}
DBase::~DBase()
{
    delete query;   //Удаляем запрос
    delete _model;   //Удаляем модель
    delete _instance;
}
QSqlRelationalTableModel* DBase::model()
{
    return _model;
}
DBase* DBase::instance()
{
    if (_instance == 0)
    {
        _instance = new DBase();
    }
    return _instance;
}
