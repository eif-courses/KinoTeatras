//
// Created by Marius on 5/3/2021.
//

#include "Filmas.h"


Filmas::Filmas(string pav, string zan, int met, double reit) {
  pavadinimas = pav;
  zanras = zan;
  metai = met;
  reitingas = reit;
}
void Filmas::SpausdintiFilmoAprasyma() const{
  cout << "Filmo pavadinimas: " << pavadinimas << endl;
  cout << "Zanras: " << zanras << endl;
  cout << "Metai: " << metai<< endl;
  cout << "Reitingas: " << reitingas << endl;
}


void Filmas::KeistiReitinga(double skaicius){
  reitingas = skaicius;
}

const string &Filmas::GetPavadinimas() const {
  return pavadinimas;
}

const string &Filmas::GetZanras() const {
  return zanras;
}

int Filmas::GetMetai() const {
  return metai;
}

double Filmas::GetReitingas() const {
  return reitingas;
}
