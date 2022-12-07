///////////////////////////////////////////////////////////
//  Postac.h
//  Implementation of the Class Postac
//  Created on:      30-lis-2022 17:20:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_5D440618_964F_483f_AC68_EDFCD96A6091__INCLUDED_)
#define EA_5D440618_964F_483f_AC68_EDFCD96A6091__INCLUDED_

#include "Plecak.h"
#include "Bron.h"

class Postac
{

public:
	Postac();
	virtual ~Postac();

	Postac(string nazwa, int pktAtakuMax, int pktAtakuMin, int pktZycia, int poziom);
	void czyZyje();
	void dodajDoPlecaka(Przedmiot* p);
	void PokazStatystykiPostaci();
	void przedstawSie();
	void przywitajSie();
	void ustawBronLewa(Bron* bron);
	void ustawBronPrawa(Bron* bron);
	void wyswietlPlecak();
	void zaatakuj(Postac* przeciwnik);
	void zaprosDoWalki(Postac* osoba);

protected:
	void obliczPktAtaku();
	void przyjmijObrazenia();

private:
	string nazwa;
	int pktAtakuMax;
	int pktAtakuMin;
	int pktZycia;
	Plecak* plecak;
	int poziom;
	Bron* rekaLewa;
	Bron* rekaPrawa;

};
#endif // !defined(EA_5D440618_964F_483f_AC68_EDFCD96A6091__INCLUDED_)
