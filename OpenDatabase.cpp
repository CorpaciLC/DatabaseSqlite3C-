#include<iostream>
#include<stdio.h>

#include "sqlite3.h"


int OpenDatabase(sqlite3 *db, int rc){

    char *zErrMsg = 0;
    rc = sqlite3_open("Database.db", &db);

    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else{
        fprintf(stderr, "Opened database successfully\n");
    }
    return 0;
    }
