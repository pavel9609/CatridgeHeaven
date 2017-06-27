#include "dbase.h"

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
QVector<QVector<QVariant> > DBase::selectPrinters()
{
    QVector<QVariant> _v;   //Вектор вариантов
    QVector<QVector<QVariant>> v;   //Вектор векторов вариантов
    return v;

}
QVector<QVector<QVariant>> DBase::selectCartridges()
{
    QVector<QVariant> _v;
    QVector<QVector<QVariant>> v;
    return v;
}
QVector<QVector<QVariant>> DBase::selectCompatibilities()
{
    QVector<QVariant> _v;
    QVector<QVector<QVariant>> v;
    return v;
}
bool DBase::Enter(QString user, QString password)
{
    bool check = query->prepare("SELECT password FROM Workers WHERE UserName=:name");   //Готовим запрос
    if (!check) throw ("Enter prepare");
    query->bindValue(":name",user); //Вставляем имя пользователя
    check = query->exec();  //Выполняем
    if(!check) throw ("Enter exec");    //Если что-то не выполнилось
    if(query->next())   {   //Пользователь найден
        if(query->value(0).toString() == password)
        {
            userName=user;
            return true;
        }
        else false;
    }
    else return false; //Пользователь не найден
}
DBase::~DBase()
{
    delete query;   //Удаляем запрос
    delete _model;   //Удаляем модель
}
QSqlRelationalTableModel* DBase::model()
{
    return _model;
}
