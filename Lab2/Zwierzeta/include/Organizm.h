#ifndef ORGANIZM_H
#define ORGANIZM_H
#include <iostream>

using namespace std;

class Organizm
{
    public:

        Organizm();
        Organizm(string dna);
        virtual ~Organizm();

        virtual void przedstawSie();

    protected:
        string dna;

    private:
};

#endif // ORGANIZM_H
