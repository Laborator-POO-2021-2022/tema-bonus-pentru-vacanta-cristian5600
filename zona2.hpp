#ifndef ZONE2_HPP
#define ZONA2_HPP

#include "baza.hpp"

class zona2: public Baza{ 

	int populatie;
	int functie[10]; //c�te persoane o anumita functie �n ordinea : 10 9 8 7 6 5 4 3 2 1 
public:
	zona2();
	zona2(int , int []);
	void afisare();
	float prezenta_vot(int [],int[],int);
	float punctaj_da(int [],int);
	float punctaj_nu(int [],int);
	bool iszona1();
	bool iszona2();
	bool iszona3();
};
#endif
