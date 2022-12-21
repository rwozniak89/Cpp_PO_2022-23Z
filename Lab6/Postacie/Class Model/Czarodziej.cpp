///////////////////////////////////////////////////////////
//  Czarodziej.cpp
//  Implementation of the Class Czarodziej
//  Created on:      30-lis-2022 17:20:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Czarodziej.h"


Czarodziej::Czarodziej(){

}

Czarodziej::Czarodziej(string nazwa, int pktAtakuMax, int pktAtakuMin, int pktZycia, int poziom, int mana) : Postac(nazwa, pktAtakuMax, pktAtakuMin, pktZycia, poziom){

    this->mana = mana;
}


Czarodziej::~Czarodziej(){

}


int Czarodziej::atakZaawansowany()
{
    cout << this->nazwa << ": " << "rozpoczyna atak zaawanowany!" <<endl;
    if(mana > 0){
        cout << this-> nazwa << ": " << "atakuje czarem!" <<endl;
        //kozystanie z klasy czar, oraz listy czarow u czarodzieja, kazdy czar moze kosztowac wiecej many, i moze miec rozne obrazenia...
        int silaAtaku = (rand() % 5) + 1;
        mana = mana - 1;
        cout << "###" << this->nazwa << ": wygenerowano pktAtaku zaawansowanego: " << silaAtaku << endl;
        return silaAtaku;
    }
    //else{
    cout << this-> nazwa << ": " << "brak many na atak czarem!" <<endl;
    return 0;
    //}

}


void Czarodziej::PokazStatystykiPostaci(){

    cout << "###(C)" << this->nazwa
    << " (Statystyki): pktAtakuMax: " << this->pktAtakuMax
     << ", pktAtakuMin: " << this->pktAtakuMin
      << ", pktZycia: " << this->pktZycia
       << ", poziom: " << this->poziom
       << ", pktMany: " << this->mana
       <<endl;
}

