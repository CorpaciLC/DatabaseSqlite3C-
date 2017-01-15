#include "table.h"
#include <QDebug>

QSqlDatabase Table::db;

int Table::createTable(QString tbName, QString columnValues) {
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:\\Users\\Luiza\\Desktop\\QDbConnection\\DataBase.db");
        db.open();
        QSqlQuery query;

        QString sql = "CREATE TABLE " +tbName + " ( " + columnValues + ");";
        query.exec(sql);
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);

    return 0;
}
int Table::insertValues(QString tableName, QString rowValues) {
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QSqlQuery query;
        QString sql = "INSERT INTO " + tableName + " VALUES(" +rowValues + ");";
        query.exec(sql);
    }
    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    return 0;
}
int Table::updateTable(QString tableName, QString rowValues){
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE", "QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
        QSqlQuery query;
        qDebug() << rowValues.count(QLatin1Char(','));
       // for(int i=0; i< rowValues.size();i++)
     //   QString sql = "UPDATE " + tableName + " SET" +rowValues + ");";
       // query.exec(sql);
    }
    return 0;
}

QString Table::readTable(QString tableName) {
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE", "QSQLITE");
        db.setDatabaseName(DATABASE_NAME);
        db.open();
    }
    QString result = "";
    QSqlQuery query;
    QString sql = "SELECT * FROM " +tableName;
    if (query.exec()) {
        if (query.next()) {
            for(int i = 0; i< query.size(); i++){
            result += query.record().value(i).toString() + "," ;
            }
        }

        else result = "404";
    }
    qDebug()<<result;
    return result;

    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
}
