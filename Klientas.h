//
// Created by Marius on 5/3/2021.
//

#ifndef KINOTEATRAS_KLIENTAS_H
#define KINOTEATRAS_KLIENTAS_H
#include <iostream>
#include "Bilietas.h"

using namespace std;

class Klientas {
private:
  string vardas;
  int amzius;
  Bilietas bilietas;
public:
  Klientas(const string &vardas, int amzius, const Bilietas &bilietas);

  const string &GetVardas() const;

  int GetAmzius() const;
  const Bilietas &GetBilietas() const;

  void SetBilietas(const Bilietas &bilietas);

};


#endif //KINOTEATRAS_KLIENTAS_H
