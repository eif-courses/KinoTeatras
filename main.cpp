#include "airbfunkcijos.h"
#include "Filmas.h"
#include "Klientas.h"
#include "database/sqlite3.h"
#include <vector>
#include "Database.h"
int main() {

  sqlite3 *db;

  db = Database::Connect("movies.db");

  Filmas greitiIrIsiute("Greiti ir įsiutę", "veiksmo/nuotykių", 2008, 9.7);

  Database::Insert(db, greitiIrIsiute);

  //Database::Display(db);


  string name = "Taxi driver";


  Database::DisplayByName(db, name);





  // ORM -> Object relation mapping


//  sqlite3 *db;
//  char *zErrMsg = 0;
//  int rc;
//
//  rc = sqlite3_open("movies.db", &db);
//
//  if( rc ) {
//    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//    return(0);
//  } else {
//    fprintf(stderr, "Opened database successfully\n");
//  }
//  sqlite3_close(db);















  vector<Filmas> filmai;

  Filmas taxidriver("Taxi driver", "Crime, Drama", 1976, 8.2);
  Filmas scarface("Scarface", "Crime, Drama", 1983, 8.3);
  filmai.emplace_back(taxidriver);
  filmai.emplace_back(scarface);


  while(true) {

    cout << "===============FILMU SARASAS======================================" << endl;
    // indeksuotas ciklas jeigu noriu manipuliuoti su duomenimis pagal indenksa
    for (int i = 0; i < filmai.size(); ++i) {
      cout << (i + 1) << ". " << filmai[i].GetPavadinimas() << " " << filmai[i].GetZanras() << endl;
    }
    cout << "0. Uzdaryti meniu"<<endl;

    int filmas;
    int vieta;

    cout << "Pasirinkite filma:";
    cin >> filmas;
    if(filmas == 0){
      break;
    }
    cout << "Pasirinkite vieta:";
    cin >> vieta;

    Bilietas bilietas(filmai[filmas - 1], vieta);

    Klientas klientas("Petras", 22, bilietas);

    klientas.GetBilietas().SpausdintiBilieta();
  }
  cout << "Programa baige darba!" << endl;

  return 0;
}
