#include <iostream>

using namespace std;
/*
2.	„Klasa Konto”
a.	//Abstrakcjonizm (w programowaniu obiektowym) jest programowym przybli¿eniem interesuj¹cej nas rzeczywistoœci;
b.	// enkapsulacja
c.	//konstruktor (super metoda, metoda specjalna) // przeci¹¿anie konstruktora, metody
d.	Konto, pola prywatne stan, waluta.
e.	Metoda publiczna pobierzStan, wyswietlStanIWalute
f.	Metody wyplac(), wplac().
g.	Konstruktor
h.	Wywolanie konstrukotow i destrukora
*/

class Konto
{

private:
    int stan = -1;
    string waluta = "brak";

public:

    Konto()
    {
        cout << "uruchomienie konstrukotra nr 1" << endl;
        stan = 0;
        waluta = "PLN";
    }

    /*
    Konto(int nowyStan){ //check inline contructors...
        cout << "uruchomienie konstrukotra nr 2" << endl;
        stan = nowyStan;
        waluta = "PLN";
    }*/

    Konto(int startowyStanKonta): Konto()  //check inline contructors...
    {
        cout << "uruchomienie konstrukotra nr 2" << endl;
        stan = startowyStanKonta;
    }

    Konto(int stan, string waluta)
    {
        cout << "uruchomienie konstrukotra nr 3" << endl;
        this->stan = stan;
        this->waluta = waluta;
    }


    void wplac(int x)
    {
        if (x > 0)
        {
            stan = stan + x; // stan += x;
            cout << "wplacono " << x << endl;
            return;
        }
        //else {
        cout << "kwota mniejsza lub rowna 0, brak wplaty!!!" << endl;
        //}
    }

    int wyplac(int x)
    {
        if( x > 0 ) //&& x < stan){
        {
            if(x < stan)
            {
                stan = stan - x;
                cout << "wyplacono " << x << endl;
                return x;
            }
        }

        cout << "kwota mniejsza lub rowna 0 lub mniejsza niz stan konta, brak wyplaty!!!" << endl;
        return 0;
    }

    int pobierzStan()
    {
        cout << "...wywolanie metody pobierzStan()" << endl; // "\n";
        return stan;
    }

    void wyswietlStanIWalute()
    {
        cout << "Stan konta: " << stan << " " << waluta << "\n";

    }

};




int main()
{
    cout << "Klasy_konto" << endl;

    Konto mojeKonto;
    //mojeKonto.

    cout << mojeKonto.pobierzStan() << endl;
    mojeKonto.wplac(-100);
    mojeKonto.wplac(500);
    int portfelRadka = mojeKonto.wyplac(1500);
    mojeKonto.wyswietlStanIWalute();
    int wyplataZKonta = mojeKonto.wyplac(100);
    mojeKonto.wyswietlStanIWalute();


    cout << "##############" << endl;
    Konto konto2(1000);
    konto2.wyswietlStanIWalute();


    cout << "##############" << endl;
    Konto konto3(5000, "EUR");
    konto3.wyswietlStanIWalute();

    return 0;
}
