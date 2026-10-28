#include "Zwierze.h"
#include <iostream>

using namespace std;

Zwierze::Zwierze()
{
    //ctor
}

Zwierze::Zwierze(string dna, string nazwa) : Organizm(dna)
{
    this->nazwa = nazwa;
}


Zwierze::~Zwierze()
{
    //dtor
}


void Zwierze::przedstawSie()
{
    cout << "Jestem zwierzeciem o nazwie: " << this->nazwa << ", moje DNA: " << this->dna << endl;
}

void Zwierze::dajGlos()
{
    cout << this->nazwa << ": *ogolny odglos zwierzecia*" << endl;
}

void Zwierze::dajRyk()
{
    cout << this->nazwa << ": Rycze pipii!" << endl;
}
