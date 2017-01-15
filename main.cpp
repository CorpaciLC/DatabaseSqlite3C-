#include <QCoreApplication>
#include "table.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Table Personal, Buget;

    Personal.createTable("PERSONAL", "NUME TEXT, FACULTATE TEXT, CNP TEXT, FILIALA TEXT");
    Personal.insertValues("PERSONAL", "'Marian', 'ACS', '29432523098', 'Bucuresti'");
//    Buget.createTable("BUGET");
    return a.exec();
}
