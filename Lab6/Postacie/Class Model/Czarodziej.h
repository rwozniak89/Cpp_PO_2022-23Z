///////////////////////////////////////////////////////////
//  Czarodziej.h
//  Implementation of the Class Czarodziej
//  Created on:      30-lis-2022 17:20:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_E597636A_547D_4863_9794_0098113B9DFD__INCLUDED_)
#define EA_E597636A_547D_4863_9794_0098113B9DFD__INCLUDED_

#include "Postac.h"

class Czarodziej : public Postac
{
    int mana;
public:
	Czarodziej();

	Czarodziej(string nazwa, int pktAtakuMax, int pktAtakuMin, int pktZycia, int poziom, int mana);


	virtual ~Czarodziej();

	int atakZaawansowany();

	void PokazStatystykiPostaci();

};
#endif // !defined(EA_E597636A_547D_4863_9794_0098113B9DFD__INCLUDED_)
