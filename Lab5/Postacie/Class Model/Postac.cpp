///////////////////////////////////////////////////////////
//  Postac.cpp
//  Implementation of the Class Postac
//  Created on:      30-lis-2022 17:20:18
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Postac.h"


Postac::Postac(){

}



Postac::~Postac(){

}





Postac::Postac(string nazwa, int pktAtakuMax, int pktAtakuMin, int pktZycia, int poziom){

    this->plecak = new Plecak();
    this->rekaLewa = NULL;
    this->rekaPrawa = NULL;

    this->nazwa = nazwa;
    this->pktAtakuMax = pktAtakuMax;
    this->pktAtakuMin = pktAtakuMin;
    this->pktZycia = pktZycia;
    this->poziom = poziom;
}

string  Postac::pobierzNazwe(){
    return nazwa;
}

bool Postac::czyZyje(){

//    if(this->pktZycia > 0)
//    {
//        return true;
//    }
//    return false;

//    return (this->pktZycia > 0) ? true : false;
    return (this->pktZycia > 0);
}


void Postac::dodajDoPlecaka(Przedmiot* p){

    plecak->dodaj(p);

}





void Postac::PokazStatystykiPostaci(){

    cout << "###" << this->nazwa
    << " (Statystyki): pktAtakuMax: " << this->pktAtakuMax
     << ", pktAtakuMin: " << this->pktAtakuMin
      << ", pktZycia: " << this->pktZycia
       << ", poziom: " << this->poziom
       <<endl;
}


void Postac::przedstawSie(){

    cout <<this->nazwa << ": " <<  generujPrzywitanie() << ", jestem " << this->nazwa  << "!"<<endl;

}

string Postac::generujPrzywitanie(){

    string tablica[] = { "Dzien dobry", "Witaj", "Ahoj", "Czesc", "Guten tag..." };
    int rozmiarTablicy = sizeof(tablica)/sizeof(string);

    int liczbaLosowa = rand() % rozmiarTablicy;

    return tablica[liczbaLosowa];
}

void Postac::zaatakuj(Postac* przeciwnik){

    cout <<this->nazwa << ": "<< "Rozpoczyna atak na przeciwnika " << przeciwnik->nazwa << " !" << endl;

    int obrazenia = 1;

    przeciwnik->przyjmijObrazenia(obrazenia);



    cout <<this->nazwa << ": "<< "Konczy atak na przeciwnika " << przeciwnik->nazwa << " !" << endl;
}

void Postac::obliczPktAtaku(){

}

void Postac::przyjmijObrazenia(int pktObrazen){

    cout <<this->nazwa << ": "<< "przyjmuje liczbe obrazen: " << pktObrazen << " !" << endl;
    this->pktZycia -= pktObrazen;

    if(this->pktZycia < 0){
        this->pktZycia = 0;
    }

    this->PokazStatystykiPostaci();
}


void Postac::przywitajSieZInnaOsoba(Postac* osoba){

    cout <<this->nazwa << ": "<< "Witam Ciebie " << osoba->nazwa << " ;)" << endl;

}


void Postac::ustawBronLewa(Bron* bron){

}


void Postac::ustawBronPrawa(Bron* bron){

}


void Postac::wyswietlPlecak(){
    plecak->wyswietl();
}





void Postac::zaprosDoWalki(Postac* osoba){
    //potrzaebna klasa Ring, metody dodaj¹ce postacie do kolekcji w ringu, metoda przyjmujaca zaproszenie do walki...
     cout <<this->nazwa << ": "<< "Zapraszam Ciebie " << osoba->nazwa << " do walki !!!! Statystyki: " << endl;
     this->PokazStatystykiPostaci();
     osoba->PokazStatystykiPostaci();
}
