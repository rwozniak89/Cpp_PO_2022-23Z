///////////////////////////////////////////////////////////
//  Plecak.h
//  Implementation of the Class Plecak
//  Created on:      30-lis-2022 17:20:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_7A36E6E7_A2ED_4d70_BFC5_52F995238AD9__INCLUDED_)
#define EA_7A36E6E7_A2ED_4d70_BFC5_52F995238AD9__INCLUDED_

#include "Przedmiot.h"
#include <vector>

class Plecak
{

public:
	Plecak();
	virtual ~Plecak();

	void dodaj(Przedmiot* przedmiot);
	void usun();
	void wyswietl();

private:
	vector<Przedmiot*>* lista;
	string nazwa;

};
#endif // !defined(EA_7A36E6E7_A2ED_4d70_BFC5_52F995238AD9__INCLUDED_)
