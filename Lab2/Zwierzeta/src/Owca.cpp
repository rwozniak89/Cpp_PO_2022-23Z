#include "Owca.h"
#include <iostream>

using namespace std;

Owca::Owca()
{
    //ctor
    this->welna = 0;
}

Owca::Owca(string dna, string nazwa, double welna) : Zwierze(dna, nazwa)
{
    this->welna = welna;
}


Owca::~Owca()
{
    //dtor
}


void Owca::przedstawSie()
{
    Zwierze::przedstawSie();
    cout << "Jestem owca i mam " << this->welna << " kg welny" << endl;
}

void Owca::dajGlos()
{
    cout << this->nazwa << ": Beeee! Meeee!" << endl;
}
