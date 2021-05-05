//
// Created by Marius on 5/3/2021.
//

#include "Filmas.h"


void Filmas::SpausdintiFilmoAprasyma() const{
  cout << "Filmo pavadinimas: " << pavadinimas << endl;
  cout << "Zanras: " << zanras << endl;
  cout << "Metai: " << metai<< endl;
  cout << "Reitingas: " << reitingas << endl;
}


void Filmas::KeistiReitinga(double skaicius){
  reitingas = skaicius;
}


int Filmas::GetMetai() const {
  return metai;
}

double Filmas::GetReitingas() const {
  return reitingas;
}

int Filmas::GetId() const {
  return id;
}

Filmas::Filmas(const string &pavadinimas, const string &zanras, int metai, double reitingas, int id) : pavadinimas(
    pavadinimas), zanras(zanras), metai(metai), reitingas(reitingas), id(id) {}

const string &Filmas::GetPavadinimas() const {
  return pavadinimas;
}

const string &Filmas::GetZanras() const {
  return zanras;
}

Filmas::Filmas(const string &pavadinimas, const string &zanras, int metai, double reitingas) : pavadinimas(pavadinimas),
                                                                                               zanras(zanras),
                                                                                               metai(metai),
                                                                                               reitingas(reitingas) {}




