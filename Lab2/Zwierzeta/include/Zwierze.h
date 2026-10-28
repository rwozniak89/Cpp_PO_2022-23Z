#ifndef ZWIERZE_H
#define ZWIERZE_H
#include <iostream>
#include "Organizm.h"

using namespace std;

class Zwierze : public Organizm
{
    public:

        Zwierze();
        Zwierze(string dna, string nazwa);
        virtual ~Zwierze();

        virtual void przedstawSie();
        virtual void dajGlos();

    protected:
        string nazwa;

    private:
};

#endif // ZWIERZE_H
