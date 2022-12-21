///////////////////////////////////////////////////////////
//  Bron.cpp
//  Implementation of the Class Bron
//  Created on:      30-lis-2022 17:20:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Bron.h"


Bron::Bron(){

}



Bron::~Bron(){

}


Bron::Bron(string nazwa, int cena, int atakMin, int atakMax, int obrona, int wytrzymalosc)
: Przedmiot(nazwa, cena), atakMin(atakMin),  atakMax(atakMax), obrona(obrona), wytrzymalosc(wytrzymalosc)
{

    this->typ1 = 1;
    this->typ2 = rodzajPrzedmiotu::bron;
}


void Bron::OpiszSie(){
    cout<< "BRON: " << " nazwa: " << nazwa << " cena: " << cena << " atakMin: " << atakMin << " atakMax: " << atakMax << " obrona: " << obrona << " wytrzymalosc: " << wytrzymalosc << endl;

}
