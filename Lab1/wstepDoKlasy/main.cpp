#include <iostream>
using namespace std;
//test_zaliczeniowy testZaliczeniowy
class Osoba
{
public:
    //stan = atrybuty
    string imie;
    string nazwisko;
    int wiek;
    //zachowanie = metody

public:
    void przedstawSie()
    {
        cout << "Jestem " << " " << imie << " " << nazwisko << ", mam lat " << wiek << endl;
    }

    Osoba(string podajImie){
        cout << "uruchomienie konstruktora z parametrem" << endl;
        imie = podajImie;
        nazwisko = "TestoweNazwisko";
        wiek = 33;
    }
    Osoba(){
         cout << "uruchomienie konstruktora z bez parametru" << endl;
    }

};
int main()
{
    cout << "Projekt wstepDoKlasy" << endl;
    int ocena;
    ocena = 5;
    Osoba kolega3;
    Osoba osoba1("Tomek");

    //osoba1.imie = "Radek";
    osoba1.nazwisko = "Wozniak";
    osoba1.wiek = 35;

    //cout << "Jestem " << osoba1.imie << osoba1.nazwisko << endl;
    //cout << "Mam " << osoba1.wiek << "lat" << endl;

    osoba1.przedstawSie();

    Osoba kolega2;
    kolega2.imie = "Patryk";
    kolega2.nazwisko = "Mieciu";
    kolega2.wiek = 30;
    kolega2.przedstawSie();
    //cout << "Jestem " << kolega2.imie << kolega2.nazwisko << endl;

    return 0;
}
