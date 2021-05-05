//
// Created by Marius on 5/5/2021.
//

#ifndef KINOTEATRAS_DATABASE_H
#define KINOTEATRAS_DATABASE_H



#include "database/sqlite3.h"
#include "Filmas.h"
#include <iostream>
#include <vector>
using namespace std;

class Database {
public:
  static sqlite3 *Connect(const string &path);
  static void CreateTable(sqlite3 *db);
  static void Insert(sqlite3 *db, const Filmas &filmas);
  static void Display(sqlite3 *db);
  static void DisplayByName(sqlite3 *db, string name);
  static int Callback(void* context,  // user-provided object (4th param to sqlite3_exec)
                      int columnCount,      // number of columns
                      char** columnValues,  // array of column values as C-style strings
                      char** columnName);    // array of column names as C-style strings);

};

#endif //KINOTEATRAS_DATABASE_H
