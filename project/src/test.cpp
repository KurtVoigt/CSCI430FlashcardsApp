#define str(s) stri(s)
#define stri(s) #s
#define DBNAME test.db
#include <stdio.h>
#include<iostream>
#include "sqlite/sqlite3.h"
#include <vector>
#include <stdlib.h>
struct myData{
    std::string NAME;
    int ID;
};

int callback(void *NotUsed, int argc, char **argv, char **azColName){
    // casts not used to a pointer to a vector<myData>
    std::vector<myData> *list = reinterpret_cast<std::vector<myData> *>(NotUsed);
    myData d;
    d.NAME = argv[0];
    d.ID = atoi(argv[1]);
    list->push_back(d);

    // Return successful
    return 0;
}

void queryNameId(sqlite3* db){
    char *zErrMsg = 0;
    int rc;
    std::vector<myData> query; 
    std::string sql = "SELECT FirstName, EmployeeId FROM 'employees';";
    sql = "CREATE TABLE IF NOT EXISTS PEOPLE ("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL);";
    rc = sqlite3_exec(db, sql.c_str(), callback, &query, &zErrMsg);
    std::cout << rc;
    for(int i = 0; i < query.size(); i++){
        std::cout << query[i].NAME << " " << query[i].ID << std::endl;
    }
}

int main(int argc, char* argv[]) {  
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   std::string sql;

   rc = sqlite3_open(str(DBNAME), &db);

   if( rc ) {
     std::cout << "DB Error: " << sqlite3_errmsg(db) << std::endl;
      return(0);
   } 
    sql = "PRAGMA foreign_keys = ON";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    std::cout << rc;
    sql = "CREATE TABLE IF NOT EXISTS KURTFAMILY("  
      "ID INTEGER PRIMARY        KEY      NOT NULL," 
      "NAME          TEXT     NOT NULL);"; 
     rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
    std::cout << rc<<std::endl;;
    sql = "INSERT INTO KURTFAMILY ('ID', 'NAME') VALUES ('1', 'kurt');";
    rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
  
    //queryNameId(db);
   // sql = "SELECT NAME, ID FROM 'KURTFAMILY';";

   // rc = sqlite3_exec(db, sql.c_str(), callback, &query, &zErrMsg);


   // std::cout << rc;
}

/*sql = "CREATE TABLE KURTFAMILY("  
      "ID INTEGER PRIMARY        KEY      NOT NULL," 
      "NAME          TEXT     NOT NULL);"; 
      
    sql = "INSERT INTO KURTFAMILY ('ID', 'NAME') VALUES ('1', 'KURT');";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO KURTFAMILY ('ID', 'NAME') VALUES ('2', 'BRENDA');";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO KURTFAMILY ('ID', 'NAME') VALUES ('3', 'MAX');";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO KURTFAMILY ('ID', 'NAME') VALUES ('4', 'KARL');";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO KURTFAMILY ('ID', 'NAME') VALUES ('5', 'KRIS');";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    sql = "INSERT INTO KURTFAMILY ('ID', 'NAME') VALUES ('6', 'MEGHANN');";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);*/