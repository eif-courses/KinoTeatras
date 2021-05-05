//
// Created by Marius on 5/3/2021.
//

#include "Bilietas.h"

const Filmas &Bilietas::GetFilmas() const {
  return filmas;
}

int Bilietas::GetVieta() const {
  return vieta;
}

double Bilietas::GetKaina() const {
  return kaina;
}

void Bilietas::SpausdintiBilieta() const{
  cout << "=====================BILIETAS========================" << endl;
  cout << "VIETA: " << vieta << endl;
  filmas.SpausdintiFilmoAprasyma();
  cout << "KAINA: " << kaina << "eur" << endl;
  cout << "======================================================" << endl;
}

Bilietas::Bilietas(const Filmas &filmas, int vieta) : filmas(filmas), vieta(vieta) {
  kaina = vieta * 2.5;
}

