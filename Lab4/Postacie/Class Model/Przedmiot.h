///////////////////////////////////////////////////////////
//  Przedmiot.h
//  Implementation of the Class Przedmiot
//  Created on:      30-lis-2022 17:20:18
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_31961657_2AB5_4c66_A68F_9E4CDCF22770__INCLUDED_)
#define EA_31961657_2AB5_4c66_A68F_9E4CDCF22770__INCLUDED_

//#include <string>
#include <iostream>
#include "rodzajPrzedmiotu.h"

using namespace std;



class Przedmiot
{

public:
	Przedmiot();
	virtual ~Przedmiot();

	Przedmiot(string nazwa, int cena);
	void OpiszSie();

protected:
	int cena;
	string nazwa;
	int typ1;
	rodzajPrzedmiotu typ2;

};
#endif // !defined(EA_31961657_2AB5_4c66_A68F_9E4CDCF22770__INCLUDED_)
