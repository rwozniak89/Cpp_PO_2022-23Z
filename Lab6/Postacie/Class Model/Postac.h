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
	bool czyZyje();
	void dodajDoPlecaka(Przedmiot* p);
	virtual void PokazStatystykiPostaci();
	void przedstawSie();
	void przywitajSieZInnaOsoba(Postac* osoba);
	void ustawBronLewa(Przedmiot* przedmiot);
	void ustawBronPrawa(Przedmiot* przedmiotn);
	void wyswietlPlecak();
	void zaatakuj(Postac* przeciwnik);
	void zaprosDoWalki(Postac* osoba);

	string  pobierzNazwe();

	virtual int atakZaawansowany();

	static int losuj(int minValue, int maxValue);
	static Postac* generujPostac();

protected:
	int obliczPktAtaku();
	void przyjmijObrazenia(int pktObrazen);


	string generujPrzywitanie();
	string nazwa;
	int pktAtakuMax;
	int pktAtakuMin;
	int pktZycia;
	Plecak* plecak;
	int poziom;
	Przedmiot* rekaLewa;
	Przedmiot* rekaPrawa;

	bool czyTrafion(int poziomPrzeciwnika);

private:

};
#endif // !defined(EA_5D440618_964F_483f_AC68_EDFCD96A6091__INCLUDED_)
