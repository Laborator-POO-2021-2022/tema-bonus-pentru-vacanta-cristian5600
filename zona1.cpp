#include "zona1.hpp"

zona1::zona1() {

  populatie = 0;
  obligatii[0] = 0;
  obligatii[1] = 0;
  obligatii[2] = 0;
  obligatii[3] = 0;
  obligatii[4] = 0;
}

zona1::zona1(int populatie, int obligatii[]) {
  this -> populatie = populatie;
  for (int i = 0; i < 5; i++) {
    this -> obligatii[i] = obligatii[i];
  }

}
void zona1::afisare() {
  cout << "populaite: " << populatie << endl;
  for (int i = 0; i < 5; i++)
    cout << " " << obligatii[i];
  cout << endl;
}
float zona1::prezenta_vot(int da[], int nu[], int aux) {
  float prezenta = 0;
  for (int i = 0; i < 5; i++)
    prezenta = prezenta + da[i] + nu[i];
  prezenta = float(prezenta / (this -> populatie - 1) * 100);
  return prezenta;
}
float zona1::punctaj_nu(int nu[], int aux) {
  float nu_suma = 0;
  for (int i = 0; i < 5; i++)
    nu_suma = nu[i] * (5 - i) * 0.2 + nu_suma;
  return nu_suma;

}
float zona1::punctaj_da(int da[], int aux) {
  float da_suma = 0;
  for (int i = 0; i < 5; i++)
    da_suma = da[i] * (5 - i) * 0.2 + da_suma;
  return da_suma;

}
