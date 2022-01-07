#include "zona2.hpp"

zona2::zona2() {

  populatie = 0;
  functie[0] = 0;
  functie[1] = 0;
  functie[2] = 0;
  functie[3] = 0;
  functie[4] = 0;
  functie[5] = 0;
  functie[6] = 0;
  functie[7] = 0;
  functie[8] = 0;
  functie[9] = 0;
}

zona2::zona2(int populatie, int functie[]) {
  this -> populatie = populatie;
  for (int i = 0; i < 10; i++) {
    this -> functie[i] = functie[i];
  }

}
void zona2::afisare() {
  cout << "populatie: " << populatie << endl;
  for (int i = 0; i < 10; i++)
    cout << " " << functie[i];
  cout << endl;
}
float zona2::prezenta_vot(int da[], int nu[], int aux) {
  float prezenta = 0;
  int votanti = 0;
  for (int i = 0; i < 5; i++)
    votanti = votanti + functie[i];
  for (int i = 0; i < 5; i++)
    prezenta = prezenta + da[i] + nu[i];
  prezenta = float(prezenta / votanti * 100);
  return prezenta;
}
float zona2::punctaj_nu(int nu[], int aux) {
  float nu_suma = 0;
  for (int i = 0; i < 5; i++)
    nu_suma = nu[i] * (10 - i) + nu_suma;
  return nu_suma;

}
float zona2::punctaj_da(int da[], int aux) {
  float da_suma = 0;
  for (int i = 0; i < 5; i++)
    da_suma = da[i] * (10 - i) + da_suma;
  return da_suma;
}
bool zona2::iszona1() {
  return false;
}
bool zona2::iszona2() {
  return true;
}
bool zona2::iszona3() {
  return false;
}
