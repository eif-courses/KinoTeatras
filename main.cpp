#include "Filmas.h"
#include "Klientas.h"
#include "database/sqlite3.h"
#include <vector>
#include "Database.h"

int main() {

  sqlite3 *db;
  string path = "movies.db";

  // Prisijungti prie db reikia po kiekvienos SQL operacijos nes funkcijoje aprasyta uzdaryti db connection
  // PRISIJUNGTI IR SUKURTI LENTELE JEIGU NEEGZISTUOJA
  db = Database::Connect(path);
  Database::CreateTableIFNotExists(db);


  Filmas bandomasis("Bandomasis agentas", "Komedija", 2020, 8.4);
  Filmas taxidriver("Taxi driver", "Crime, Drama", 1976, 8.2, 0);
  Filmas scarface("Scarface", "Crime, Drama", 1983, 8.3, 0);

  // ITERPTI
  db = Database::Connect(path);
  Database::Insert(db, bandomasis);

  db = Database::Connect(path);
  Database::Insert(db, taxidriver);

  db = Database::Connect(path);
  Database::Insert(db, scarface);

  // ATLIKTI UZKLAUSA IS DB IR PRISKIRTI VEKTORIUI
  db = Database::Connect(path);

  string name = "Bandomasis agentas";

  vector<Filmas> filmaiIsDB = Database::DisplayByName(db, name);

  // IPRASTAS VEKTORIUS DARBUI SU DUOMENIMIS IS DB
  for (const auto& it: filmaiIsDB) {
    cout <<"Agento id: "<<it.GetId() << " "<< it.GetPavadinimas() << endl;
  }


//
//  vector<Filmas> filmai;
//
//  Filmas taxidriver("Taxi driver", "Crime, Drama", 1976, 8.2, 0);
//  Filmas scarface("Scarface", "Crime, Drama", 1983, 8.3, 0);
//  filmai.emplace_back(taxidriver);
//  filmai.emplace_back(scarface);
//
//
//  while(true) {
//
//    cout << "===============FILMU SARASAS======================================" << endl;
//    // indeksuotas ciklas jeigu noriu manipuliuoti su duomenimis pagal indenksa
//    for (int i = 0; i < filmai.size(); ++i) {
//      cout << (i + 1) << ". " << filmai[i].GetPavadinimas() << " " << filmai[i].GetZanras() << endl;
//    }
//    cout << "0. Uzdaryti meniu"<<endl;
//
//    int filmas;
//    int vieta;
//
//    cout << "Pasirinkite filma:";
//    cin >> filmas;
//    if(filmas == 0){
//      break;
//    }
//    cout << "Pasirinkite vieta:";
//    cin >> vieta;
//
//    Bilietas bilietas(filmai[filmas - 1], vieta);
//
//    Klientas klientas("Petras", 22, bilietas);
//
//    klientas.GetBilietas().SpausdintiBilieta();
//  }
//  cout << "Programa baige darba!" << endl;

  return 0;
}
