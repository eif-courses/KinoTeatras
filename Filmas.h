//
// Created by Marius on 5/3/2021.
//

#ifndef KINOTEATRAS_FILMAS_H
#define KINOTEATRAS_FILMAS_H
#include <iostream>
using namespace std;

class Filmas {

private: // private naudojama ir pasiekiama tik Filmas klaseje
 string pavadinimas;
  string zanras;
  int metai;
  double reitingas;
  int id;

public: // public laukai ir metodai matomi visur arba yra viesi


  Filmas(const string &pavadinimas, const string &zanras, int metai, double reitingas, int id);

  Filmas(const string &pavadinimas, const string &zanras, int metai, double reitingas);

  const string &GetPavadinimas() const;

  const string &GetZanras() const;

  int GetId() const;



  int GetMetai() const;

  double GetReitingas() const;

  void KeistiReitinga(double skaicius);

  void SpausdintiFilmoAprasyma() const;

protected: // paveldejimas tik vaikines klases gali matyti ir pasiekti

};

#endif //KINOTEATRAS_FILMAS_H
