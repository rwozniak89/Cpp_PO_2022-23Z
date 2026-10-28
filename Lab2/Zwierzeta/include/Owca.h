#ifndef OWCA_H
#define OWCA_H
#include <iostream>
#include "Zwierze.h"

using namespace std;

class Owca : public Zwierze
{
    public:

        Owca();
        Owca(string dna, string nazwa, double welna);
        virtual ~Owca();

        virtual void przedstawSie();
        virtual void dajGlos();

    protected:
        double welna; // ilosc welny w kg

    private:
};

#endif // OWCA_H
