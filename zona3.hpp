#ifndef ZONE1_HPP
#define ZONA1_HPP

#include "baza.hpp"

class zona3: public Baza{ 

	int populatie;
	int varsta[4]; //numarul de persoane din categoriile de vârsta în ordinea:0-14 14-20 20-40 40+ 
public:
	zona3();
	zona3(int , int []);
	void afisare();
	float prezenta_vot(int [],int [],int);
	float punctaj_da(int [],int );
	float punctaj_nu(int [],int );


};
#endif
