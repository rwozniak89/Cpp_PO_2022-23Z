#include "WilkX.h"
#include <iostream>

using namespace std;

WilkX::WilkX()
{
    //ctor
    this->zjedzoneOwce = 0;
}

WilkX::WilkX(string dna, string nazwa, double welna) : Owca(dna, nazwa, welna)
{
    this->zjedzoneOwce = 0;
}


WilkX::~WilkX()
{
    //dtor
}


void WilkX::przedstawSie()
{
    Owca::przedstawSie();
    cout << "...a tak naprawde jestem wilkiem! Zjadlem juz " << this->zjedzoneOwce << " owiec" << endl;
}

void WilkX::dajGlos()
{
    cout << this->nazwa << ": Auuuuuu! Grrrrrr!" << endl;
}

void WilkX::dajRyk()
{
    cout << this->nazwa << ": Rycze AUUUUUUUUUUUUU!" << endl;
}

void WilkX::zjedzOwce(Owca& owca)
{
    this->zjedzoneOwce++;
    cout << this->nazwa << " podkrada sie do stada i zjada owce!" << endl;
    owca.dajGlos();
}

int WilkX::ileZjedzonychOwiec()
{
    return this->zjedzoneOwce;
}
