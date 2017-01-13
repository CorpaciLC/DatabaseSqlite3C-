#include <stdio.h>
#include "sqlite3.h"

int OpenDatabase(sqlite3 *db, int rc);

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void executeSqlStatement(sqlite3 *db, char* sql){

    int rc;
    char *zErrMsg = 0;
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
    }
    else{
        fprintf(stdout, "Table created successfully\n");
    }
}
void CreateTablePersonal(sqlite3* db, char *sql){
    sql = "CREATE TABLE PERSONAL("  \
        "CNP VARCHAR(14) PRIMARY KEY     NOT NULL," \
        "NUME TEXT NOT NULL);";
    executeSqlStatement(db, sql);
}
    void CreateTableBuget(sqlite3* db, char *sql){
    sql = "CREATE TABLE BUGET("  \
        "CAMP TEXT );";
    executeSqlStatement(db, sql);
}
void CreateTable3(sqlite3* db, char *sql){
    sql = "CREATE TABLE TABLE3("  \
        "CAMP TEXT);";
    executeSqlStatement(db, sql);
}
void CreateTable4(sqlite3* db, char *sql){
    sql = "CREATE TABLE TABLE4("  \
        "CAMP TEXT );";
    executeSqlStatement(db, sql);
}
void CreateTable5(sqlite3* db, char *sql){
    sql = "CREATE TABLE TABLE5("  \
        "CAMP TEXT);";
    executeSqlStatement(db, sql);
}

int main(int argc, char* argv[])
{
   sqlite3 *db;
   int rc;
   char *sql;

   rc = sqlite3_open("test.db", &db);

    OpenDatabase(db, rc);

    CreateTablePersonal(db, sql);
    CreateTableBuget(db, sql);
    CreateTable3(db, sql);
    CreateTable4(db, sql);
    CreateTable5(db, sql);

    sqlite3_close(db);
}
