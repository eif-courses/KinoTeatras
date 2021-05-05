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
int Database::Callback(void *context, int columnCount, char **columnValues, char **columnName) {

  for (int i = 0; i < columnCount; i++) {
    cout << columnValues[i] << " ";
  }
  cout << endl;

  return 0;
}
void Database::Insert(sqlite3 *db, const Filmas &filmas) {

  sqlite3_stmt *statment;
  string sql;
  sql = "insert into Filmas VALUES (?,?,?,?,?)";

  if (sqlite3_prepare_v2(db,
                         sql.c_str(),
                         -1,
                         &statment,nullptr)!= SQLITE_OK) {
    cout << "SOrry not working!"<< endl;
  }


  // insert into Filmas VALUES (null,?,?,?)
  if (sqlite3_bind_null(statment, 1) != SQLITE_OK) {
    //printf("\nCould not bind double.\n");
    cout << "\nCould not bind null.\n";
    return;
  }

  // insert into Filmas VALUES (null,"Taxi",?,?)
  if (sqlite3_bind_text(
      statment,
      2,  // Index of wildcard
      filmas.GetPavadinimas().c_str(), // Data as -> const * char
      filmas.GetPavadinimas().length(), // Data length
      SQLITE_STATIC
  ) != SQLITE_OK) {
    cout << "\nCould not bind text.\n";
    return;
  }

  // insert into Filmas VALUES (null,"Taxi","Drama",?)
  if (sqlite3_bind_text(
      statment,
      3,  // Index of wildcard
      filmas.GetZanras().c_str(), // Data as -> const * char
      filmas.GetZanras().length(), // Data length
      SQLITE_STATIC
  ) != SQLITE_OK) {
    cout << "\nCould not bind text.\n";
    return;
  }

  if (sqlite3_bind_int(
      statment,
      4,  // Index of wildcard
      filmas.GetMetai()
  ) != SQLITE_OK) {
    printf("\nCould not bind int.\n");
    return;
  }

  if (sqlite3_bind_double(
      statment,
      5,  // Index of wildcard
      filmas.GetReitingas()
  ) != SQLITE_OK) {
    printf("\nCould not bind double.\n");
    return;
  }

  if (sqlite3_step(statment) != SQLITE_DONE) {
    printf("\nCould not step (execute) stmt.\n");
    return;
  }

  printf("\n");
  //select_stmt("select * from foo");

  sqlite3_close(db);
}

void Database::Display(sqlite3 *db) {
  char *zErrMsg = nullptr;
  const char *data = "Callback function called";

  /* Create SQL statement */
  string sql = "SELECT * from Filmas";

  // boolean true -> 1, false -> 0 nera c kalboj naudojo int 0,1

  /* Execute SQL statement */
  int rc = sqlite3_exec(db, sql.c_str(), Callback, (void *) data, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Operation done successfully\n");
  }
}

void Database::DisplayByName(sqlite3 *db, string name) {

  char *zErrMsg = nullptr;
  const char *data = "Callback function called";
  sqlite3_stmt *res;
  string sql = "select pavadinimas, zanras, metai, reitingas from Filmas where pavadinimas==?";

  int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &res, 0);

  if (rc == SQLITE_OK) {
    sqlite3_bind_text(res, 1, name.c_str(), name.length(), SQLITE_STATIC);
  } else {
    fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
  }

  int step = sqlite3_step(res);

  if (step == SQLITE_ROW) {

    cout << sqlite3_column_text(res, 0) << " pavadinimas"<< endl;
    cout << sqlite3_column_text(res, 1) << " zanras"<< endl;
    cout << sqlite3_column_int(res, 2) << " metai"<< endl;
    cout << sqlite3_column_double(res, 3) << " reitingas"<< endl;

  }

  sqlite3_finalize(res);
  sqlite3_close(db);






  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Operation done successfully\n");
  }
}

// select pavadinimas, zanras, metai, reitingas from Filmas where pavadinimas=='Taxi driver'
