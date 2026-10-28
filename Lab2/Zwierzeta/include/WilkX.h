#ifndef WILKX_H
#define WILKX_H
#include <iostream>
#include "Owca.h"

using namespace std;

// Wilk w owczej skorze - z zewnatrz wyglada jak owca
class WilkX : public Owca
{
    public:

        WilkX();
        WilkX(string dna, string nazwa, double welna);
        virtual ~WilkX();

        virtual void przedstawSie();
        virtual void dajGlos();

        void zjedzOwce(Owca& owca);
        int ileZjedzonychOwiec();

    private:
        int zjedzoneOwce;
};

#endif // WILKX_H
