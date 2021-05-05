//
// Created by Marius on 5/3/2021.
//

#ifndef KINOTEATRAS_BILIETAS_H
#define KINOTEATRAS_BILIETAS_H
#include <iostream>
#include "Filmas.h"

using namespace std;

class Bilietas {
private:
  Filmas filmas;
  int vieta;
  double kaina;
public:
  Bilietas(const Filmas &filmas, int vieta);

  const Filmas &GetFilmas() const;
  int GetVieta() const;
  double GetKaina() const;
  void SpausdintiBilieta() const;
};


#endif //KINOTEATRAS_BILIETAS_H
