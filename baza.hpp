#ifndef BAZA_HPP
#define BAZA_HPP

#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>

using namespace std;

class Baza{
public:
	
	virtual void afisare() = 0;
	virtual ~Baza() = 0;
	
	virtual bool iszona1() = 0;
	virtual bool iszona2() = 0;
	virtual bool iszona3() = 0;
	virtual float prezenta_vot(int [],int [],int) = 0;
	virtual float punctaj_nu(int [],int) = 0;
	virtual float punctaj_da(int [],int) = 0;
	
	
};

#endif
