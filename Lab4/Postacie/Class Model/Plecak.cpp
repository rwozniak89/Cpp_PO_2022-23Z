///////////////////////////////////////////////////////////
//  Plecak.cpp
//  Implementation of the Class Plecak
//  Created on:      30-lis-2022 17:20:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Plecak.h"

#include <iostream>
using namespace std;


Plecak::Plecak(){

    lista = new vector<Przedmiot*>();
}



Plecak::~Plecak(){

}





void Plecak::dodaj(Przedmiot* przedmiot){

    if(lista->size() < 3){
        cout << "dodano do plecka: ";
        przedmiot->OpiszSie();
        lista->push_back(przedmiot);
    }
    else{
        cout << "brak miejsca w plecaku ";
    }


}


void Plecak::usun(){

}


void Plecak::wyswietl(){

    cout << "Zawartosc plecaka: " << endl;
    if(lista->size() != 0 ){

        for(int i = 0; i< lista->size(); i++)
        {
            ((*lista)[i])->OpiszSie();
        }
    }
    else{
        cout << "brak przedmiotow" << endl;
    }

}
