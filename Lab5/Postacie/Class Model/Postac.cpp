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


void Postac::czyZyje(){

}


void Postac::dodajDoPlecaka(Przedmiot* p){

    plecak->dodaj(p);

}


void Postac::obliczPktAtaku(){

}


void Postac::PokazStatystykiPostaci(){

    cout << "Statystyki dla : Postac: " << this->nazwa
    << ", pktAtakuMax: " << this->pktAtakuMax
     << ", pktAtakuMin: " << this->pktAtakuMin
      << ", pktZycia: " << this->pktZycia
       << ", poziom: " << this->poziom
       <<endl;
}


void Postac::przedstawSie(){

    cout << "Jestem " << this->nazwa <<endl;

}


void Postac::przyjmijObrazenia(){

}


void Postac::przywitajSie(){

}


void Postac::ustawBronLewa(Bron* bron){

}


void Postac::ustawBronPrawa(Bron* bron){

}


void Postac::wyswietlPlecak(){
    plecak->wyswietl();
}


void Postac::zaatakuj(Postac* przeciwnik){

}


void Postac::zaprosDoWalki(Postac* osoba){

}
