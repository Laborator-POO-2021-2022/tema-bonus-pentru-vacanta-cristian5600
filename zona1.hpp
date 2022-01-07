#ifndef ZONE1_HPP
#define ZONA1_HPP
#include "baza.hpp"
 //am folosit https://codebeautify.org/cpp-formatter-beautifier
class zona1: public Baza {

  int populatie;
  int obligatii[5]; //nr persoane in ordinea numarului de obligatii respectate 4 3 2 1 0
  public:
    zona1();
  zona1(int, int[]);
  void afisare();
  float prezenta_vot(int[], int[], int);
  float punctaj_da(int[], int);
  float punctaj_nu(int[], int);


};
#endif
