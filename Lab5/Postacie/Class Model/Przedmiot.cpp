///////////////////////////////////////////////////////////
//  Przedmiot.cpp
//  Implementation of the Class Przedmiot
//  Created on:      30-lis-2022 17:20:18
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Przedmiot.h"


Przedmiot::Przedmiot(){

}



Przedmiot::~Przedmiot(){

}





Przedmiot::Przedmiot(string nazwa, int cena){
    this->typ1 = 0;
    this->typ2 = rodzajPrzedmiotu::prosty;
    this->nazwa = nazwa;
    this->cena = cena;
}


void Przedmiot::OpiszSie(){
    cout << "Opis: Przedmiot: " <<this->nazwa << ", cena: " << this->cena << endl;
}
