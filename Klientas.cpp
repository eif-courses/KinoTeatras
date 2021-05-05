//
// Created by Marius on 5/3/2021.
//

#include "Klientas.h"

Klientas::Klientas(const string &vardas, int amzius, const Bilietas &bilietas) : vardas(vardas), amzius(amzius),
                                                                                 bilietas(bilietas) {}

const string &Klientas::GetVardas() const {
  return vardas;
}

int Klientas::GetAmzius() const {
  return amzius;
}

const Bilietas &Klientas::GetBilietas() const {
  return bilietas;
}

void Klientas::SetBilietas(const Bilietas &bilietas) {
  Klientas::bilietas = bilietas;
}
