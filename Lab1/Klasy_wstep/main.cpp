#include <iostream>

using namespace std;
/*
1.	„Klasy_wstep”.
a.	Zasada, cecha Abstrakcjonizmu.
b.	Utwórz klasê Osoba, atrybuty imie, nazwisko, wiek.
c.	W main, spróbuj utworzyæ w prosty sposób obiekt i przypisaæ wartoœci dla pól.
d.	Dodaj public w klasie
e.	W main, spróbuj przypisaæ wartoœci dla pól.
int liczba1 = 1;
    float liczba2 = 2.1;

    Osoba obiekt1;
    obiekt1.imie = "Radek";
    obiekt1.nazwisko = "Woz";
    obiekt1.wiek = 32;
f.	Wyœwietl informacjê:
cout << "Mam na imie " << obiekt1.imie << ", mam lat " << obiekt1.wiek << "\n";

g.	W klasie, dodaj metodê przedstawSie();
h.	Wywo³aj metodê.
*/

class Osoba
{
public:
    //stan = atrybuty
    string imie;
    string nazwisko;
    int wiek;

    Osoba(){
        cout << "...utworzenie nowego obiektu za pomoca konstrukltora nr 1" << endl;
    }

    Osoba(string nazwaZwrotu){
        cout << "...utworzenie nowego obiektu a pomoca konstrukltora nr 2" << endl;
        ustawZwrotGrzeczsciowy(nazwaZwrotu);
    }

    //zachowanie = metody
    void przedstawSie()
    {
        cout << "Jestem " << zwrotGrzenosicowy << " " << imie << " " << nazwisko << ", mam lat " << wiek << endl;
    }

private:
    string zwrotGrzenosicowy;

    void ustawZwrotGrzeczsciowy(string nazwa){
        zwrotGrzenosicowy = nazwa;
        cout << "...ustawiono... " << nazwa << endl;
    }

};

#include "Persona.h"


int main()
{
    cout << "Klasy_wstep!" << endl;

    int zmiennaA = 0;

    Osoba osoba1;
    osoba1.imie = "Radek";
    osoba1.nazwisko = "Wozniak";
    osoba1.wiek = 32;

    cout << "Jestem " << osoba1.imie << endl;

    osoba1.przedstawSie();
    osoba1.nazwisko = "Iksinski";
    osoba1.przedstawSie();
    //osoba1.ustawZwrotGrzeczsciowy("Pan");

    Osoba osoba2("Pan");
    osoba2.imie = "Marek";
    osoba2.nazwisko = "Januszek";
    osoba2.wiek = 22;
    osoba2.przedstawSie();

    cout << "%%%%%%%%%%% " << endl;

    Persona p1;
    p1.imie = "Patryk";
    p1.wiek = 22;
    p1.przedstawSie();


    return 0;
}
