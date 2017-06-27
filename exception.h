#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>
class Exception{
public:
    Exception(QString error){_Error = error;}       //Чтобы можно было искать где вылетело
    QString Error(){return _Error;}                 //Вывод ошибки
private:
    QString _Error;
};

#endif // EXCEPTION_H
