#include "zona3.hpp"

zona3::zona3() {

  populatie = 0;
  varsta[0] = 0;
  varsta[1] = 0;
  varsta[2] = 0;
  varsta[3] = 0;
}

zona3::zona3(int populatie, int varsta[]) {
  this -> populatie = populatie;
  for (int i = 0; i < 4; i++) {
    this -> varsta[i] = varsta[i];
  }
}
void zona3::afisare() {

  cout << "populaite: " << populatie << endl;
  for (int i = 0; i < 4; i++)
    cout << " " << varsta[i];
  cout << endl;
}
float zona3::prezenta_vot(int da[], int nu[], int ani) {
  int votanti = 0;
  float prezenta = 0;
  if (ani == 14)
    votanti = varsta[1] + varsta[2] + varsta[3];
  else if (ani == 20)
    votanti = varsta[2] + varsta[3];
  else if (ani == 40)
    votanti = varsta[3];
  prezenta = da[0] + nu[0];
  prezenta = prezenta / votanti * 100;
  return prezenta;

}
float zona3::punctaj_nu(int nu[], int aux) {

  return nu[0];

}
float zona3::punctaj_da(int da[], int aux) {

  return da[0];

}
bool zona3::iszona1() {
  return false;
}
bool zona3::iszona2() {
  return false;
}
bool zona3::iszona3() {
  return false;
}
