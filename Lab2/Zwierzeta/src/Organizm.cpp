#include "Organizm.h"
#include <iostream>

using namespace std;

Organizm::Organizm()
{
    //ctor
}

Organizm::Organizm(string dna)
{
    this->dna = dna;
}


Organizm::~Organizm()
{
    //dtor
}


void Organizm::przedstawSie()
{

    cout << "Jestem prostym organizmem, mam tylko DNA: " << this->dna << endl;
}
