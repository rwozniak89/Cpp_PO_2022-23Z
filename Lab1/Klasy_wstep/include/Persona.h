#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona
{
    public:
        string imie;
        string nazwisko;
        int wiek;

        void przedstawSie();


        Persona();
        virtual ~Persona();

    protected:

    private:
};

#endif // PERSONA_H
