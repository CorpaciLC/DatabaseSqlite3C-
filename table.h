#ifndef TABLE_H
#define TABLE_H

#include <QDebug>
#include <QSqlDatabase>
#include <QsqlRecord>
#include <Qsqlquery>
#include <QString>

#define DATABASE_NAME "C:\\Users\\Luiza\\Desktop\\QDbConnection\\DataBase.db" // schimba cu adresa folderului unde ai tu proiectul

class Table
{
public:
    static int createTable(QString tableName, QString ColumnValues);
    static int insertValues(QString tableName, QString rowValues);
    static int updateTable(QString tableName, QString rowValues);
    QString readTable(QString tableName);
    QString readTableCNP(QString CNP, QString tableName);
    static int deleteTable(QString tableName);

    static QSqlDatabase db;
};

#endif // TABLE_H
