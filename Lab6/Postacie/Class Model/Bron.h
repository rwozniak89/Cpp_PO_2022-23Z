///////////////////////////////////////////////////////////
//  Bron.h
//  Implementation of the Class Bron
//  Created on:      30-lis-2022 17:20:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_3754B85E_6ACC_46e1_805E_CF043ED6B759__INCLUDED_)
#define EA_3754B85E_6ACC_46e1_805E_CF043ED6B759__INCLUDED_

#include "Przedmiot.h"

class Bron : public Przedmiot
{

public:
	Bron();
	virtual ~Bron();

	Bron(string nazwa, int cena, int atakMin, int atakMax, int obrona, int wytrzymalosc);
	void OpiszSie();

public:
	int atakMax;
	int atakMin;
	int obrona;
	int wytrzymalosc;

};
#endif // !defined(EA_3754B85E_6ACC_46e1_805E_CF043ED6B759__INCLUDED_)
