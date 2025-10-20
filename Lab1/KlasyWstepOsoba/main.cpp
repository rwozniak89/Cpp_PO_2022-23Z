#include <iostream>

using namespace std;

class Osoba
{
private:
    //stan = atrybuty
    string imie;
    string nazwisko;
    int wiek;
public:
    //zachowanie = metody
    void przedstawSie()
    {
        cout << "Jestem " << " " << imie << " " << nazwisko << ", mam lat " << wiek << endl;
    }

    Osoba(string podajImie, string nazw, int wiek): Osoba(){
        cout << "uruchomienie konstruktora z parametrem" << endl;
        imie = podajImie;
        nazwisko = nazw;
        this->wiek = wiek;
    }
    Osoba(){
         cout << "uruchomienie konstruktora z bez parametru" << endl;
         imie = "imie1";
         nazwisko = "nazwisko1";
         wiek = 0;

    }

    void ustawImie(string nadajImie)
    {
        imie = nadajImie;
    }
};

int main()
{
    cout << "Wprowadzenie do abstrakcji w PO" << endl;
    int liczba1 = 1;
    float liczba2 = 2.1;
    Osoba czlowiek1("Radek", "Woz", 33);

    //czlowiek1.imie = "Radek";
    czlowiek1.przedstawSie();
    czlowiek1.ustawImie("Marek");
    czlowiek1.przedstawSie();
    //czlowiek1.nazwisko = "Wozniak";
    //czlowiek1.wiek = 35;

    //cout << "Jestem " << czlowiek1.imie << czlowiek1.nazwisko << endl;
    //cout << "Mam " << czlowiek1.wiek << "lat" << endl;
    czlowiek1.przedstawSie();

    Osoba kolega2;

    //kolega2.imie = "patryk";
    //kolega2.nazwisko = "Nowak";
    //kolega2.wiek = 22;

    //cout << "Jestem " << kolega2.imie << kolega2.nazwisko << endl;
    //cout << "Mam " << kolega2.wiek << "lat" << endl;
    kolega2.przedstawSie();

    return 0;
}
