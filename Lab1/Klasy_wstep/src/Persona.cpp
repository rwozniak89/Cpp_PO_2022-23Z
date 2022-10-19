#include "Persona.h"

Persona::Persona()
{
     cout<< "konstruktor Persony" << endl;
}

Persona::~Persona()
{
     cout<< "destruktor Persony" << endl;
}


void Persona::przedstawSie(){
    cout << "Jestem " << imie << ", mam lat " << this->wiek  <<"\n";
}
