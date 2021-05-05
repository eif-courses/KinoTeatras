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
  static void CreateTableIFNotExists(sqlite3 *db);
  static void Insert(sqlite3 *db, const Filmas &filmas);
  static vector<Filmas> DisplayByName(sqlite3 *db, string name);
};

#endif //KINOTEATRAS_DATABASE_H
