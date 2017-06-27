#include "dbase.h"

DBase::DBase()
{
    try //Чтобы облегчить сброс, если что-то не так
    {
        db = QSqlDatabase::addDatabase("QSQLITE");    //Добавляем базу, метод может быть только статических
        if (!db.isValid()) throw Exception("Valid");    //Если что-то не получается
        db.setDatabaseName(QDir::currentPath()+"/Cartridge.sqlite");    //Отправляем к исполняемому файлу
        if (!db.open()) throw Exception("Open");    //Открываем и кричим, если что-то не так.
        query = new QSqlQuery(db);  //Связываем запрос с базой

    }
    catch(Exception e)
    {
        if (db.lastError().text() != " ") qDebug()<<e.Error()<<db.lastError().text();
        else qDebug()<<e.Error()<<query->lastError().text(); //Ошибка, которую мы указали и ошибка базы данных
    }
}
QVector<QVector<QVariant>> DBase::selectPrinters()
{
    QVector<QVariant> _v;   //Вектор вариантов
    QVector<QVector<QVariant>> v;   //Вектор векторов вариантов
    try
    {
        check = query->exec("SELECT * FROM Printers");
        if (!check) throw Exception("Printer selection Error");
        while (query->next()) {
                for (int i = 1;i<query->size();i++)
                {
                    _v.push_back(query->value(i));
                }
                v.push_back(_v);
                _v.clear();
            }
    }
    catch(Exception e)
    {
        v.clear();
        qDebug()<<e.Error()<<query->lastError();
        return v;
    }
    return v;

}
QVector<QVector<QVariant>> DBase::selectCartridges()
{
    QVector<QVariant> _v;
    QVector<QVector<QVariant>> v;
    try
    {
        check = query->exec("SELECT * FROM Cartridges");
        if (!check) throw Exception("Cartridge selection Error");
        while (query->next()) {
                int type = query->value(3).toInt();
                QSqlQuery query2(db);
                check = query2.prepare("SELECT * From CartridgeTypes WHERE id = :id");
                query2.bindValue(":id",type);
                if(!query2.exec()) throw ("Types Error");
                while(query2.next())
                {

                    _v<<query2.value(1)<<query2.value(2)<<query2.value(3)<<query2.value(4)<<
                              query2.value(5)<<query2.value(6)<<query2.value(7)<<query->value(1)<<query->value(2);
                }
                v.push_back(_v);
                _v.clear();
            }
    }
    catch(Exception e)
    {
        v.clear();
        qDebug()<<e.Error()<<query->lastError();
        return v;
    }
    return v;
}
QVector<QVector<QVariant>> DBase::selectCompatibilities()
{
    QVector<QVariant> _v;
    QVector<QVector<QVariant>> v;
    try
    {
        check = query->exec("SELECT * FROM Compatibility");
        if (!check) throw Exception("Comp selection Error");
        while (query->next()) {
                QSqlQuery query2(db),query3(db);
                int cartridge = query->value(0).toInt();
                int printer = query->value(1).toInt();
                check = query2.prepare("SELECT Name From CartridgeTypes WHERE id = :id");
                query2.bindValue(":id",cartridge);
                if (!check) throw ("types not prepares");
                check = query2.exec();
                if (!check) throw ("types not execute");
                while(query2.next())
                {
                    _v.push_back(query2.value(2));
                }
                check = query3.prepare("SELECT Name From Printers WHERE id = :id");
                query3.bindValue(":id",printer);
                query3.exec();
                while(query3.next())
                {
                    _v.push_back(query3.value(1));
                }
                v.push_back(_v);
                _v.clear();

            }
    }
    catch(Exception e)
    {
        v.clear();
        qDebug()<<e.Error()<<query->lastError();
        return v;
    }
    return v;
}
bool DBase::Enter(QString user, QString password)
{
    bool check = query->prepare("SELECT password FROM Workers WHERE UserName=:name");   //Готовим запрос
    if (!check) throw ("Enter prepare");
    query->bindValue(":name",user); //Вставляем имя пользователя
    check = query->exec();  //Выполняем
    if(!check) throw ("Enter exec");
    if(query->next())
    {
        if(query->value(0).toString() == password) return true;
        else return false;
    }
    return false;
}
