#ifndef DBASE_H
#define DBASE_H

#include <QSqlDatabase>

class DBase
{
public:
    DBase();
private:
    QSqlDatabase cartridge;
};

#endif // DBASE_H
