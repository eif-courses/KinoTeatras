//
// Created by Marius on 5/5/2021.
//

#include "Database.h"

sqlite3 *Database::Connect(const string &path) {
  sqlite3 *db; // sukuriame nauja db egzemplioriu
  sqlite3_open(path.c_str(), &db); // atidarom db faila
  if (db == nullptr) {
    cout << "Could not open database." << endl;
    return nullptr;
  } else {
    cout << "Connected to database successfully!!!" << endl;
    return db;
  }
}

void Database::Insert(sqlite3 *db, const Filmas &filmas) {

  sqlite3_stmt *statment;
  string sql = "insert into Filmas VALUES (?,?,?,?,?)";

  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &statment, nullptr) != SQLITE_OK) {
    cout << "SOrry not working! Gali buti duomenu bazes Connection blogas arba neegzistuoja!" << endl;
    return;
  }
  if (sqlite3_bind_null(statment, 1) != SQLITE_OK) {
    cout << "\nCould not bind null.\n";
    return;
  }
  if (sqlite3_bind_text(statment, 2, filmas.GetPavadinimas().c_str(), filmas.GetPavadinimas().length(),
                        SQLITE_STATIC) != SQLITE_OK) {
    cout << "\nCould not bind text.\n";
    return;
  }
  if (sqlite3_bind_text(statment, 3, filmas.GetZanras().c_str(), filmas.GetZanras().length(), SQLITE_STATIC) !=
      SQLITE_OK) {
    cout << "\nCould not bind text.\n";
    return;
  }
  if (sqlite3_bind_int(statment, 4, filmas.GetMetai()) != SQLITE_OK) {
    cout << "\nCould not bind int.\n";
    return;
  }
  if (sqlite3_bind_double(statment, 5, filmas.GetReitingas()) != SQLITE_OK) {
    cout << "\nCould not bind double.\n";
    return;
  }
  if (sqlite3_step(statment) != SQLITE_DONE) {
    cout << "\nnCould not step (execute) stmt.\n";
    return;
  }
  cout << "\n";
  sqlite3_finalize(statment);
  sqlite3_close(db);
}

vector<Filmas> Database::DisplayByName(sqlite3 *db, string name) {
  sqlite3_stmt *res;
  string sql = "select * from Filmas where pavadinimas==?";

  int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);

  if (rc == SQLITE_OK) {
    sqlite3_bind_text(res, 1, name.c_str(), name.length(), SQLITE_STATIC);
  } else {
    cout << "Failed to execute: " << sqlite3_errmsg(db) << endl;
  }

  vector<Filmas> filmai; // laikinas sąrašas duomenims

  // Skaitomi duomenu bazės įrašai
  while ((rc = sqlite3_step(res)) != SQLITE_DONE) {
    // Konvertuojame duomenu bazės grąžinamą reikšmę
    // 'unsigned const char*' į string tipą
    basic_string<unsigned char> col1 = sqlite3_column_text(res, 1);
    basic_string<unsigned char> col2 = sqlite3_column_text(res, 2);
    string pavadinimas(col1.begin(), col1.end());
    string zanras(col2.begin(), col2.end());

    int metai = sqlite3_column_int(res, 3);
    double reitingas = sqlite3_column_double(res, 4);
    int id = sqlite3_column_int(res, 0);
    //------------------------------------------------------

    Filmas filmas(pavadinimas, zanras, metai, reitingas, id);
    filmai.emplace_back(filmas);
  }
  sqlite3_finalize(res);
  sqlite3_close(db);

  return filmai;
}

void Database::CreateTableIFNotExists(sqlite3 *db) {

  string sql = "CREATE TABLE IF NOT EXISTS Filmas("  \
      "id INTEGER PRIMARY KEY AUTOINCREMENT," \
      "pavadinimas           TEXT    NOT NULL," \
      "zanras            TEXT     NOT NULL," \
        "metai            INT     NOT NULL," \
      "reitingas        REAL );";

  int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);

  if (rc == SQLITE_OK) {
    cout << "Database table created!!!" << endl;
  } else {
    cout << "Failed to execute or table already exists!" << sqlite3_errmsg(db) << endl;
  }

  sqlite3_close(db);
}
