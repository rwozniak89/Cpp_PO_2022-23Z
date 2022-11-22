#include <iostream>

using namespace std;


class Adam {
friend class Bartek;

public:
    string nazwa;

private:
    int kasa;

public:
    Adam() {
        kasa = 1;
        nazwa = "Adamek";

    }
    int getKasa() {
        cout << kasa << endl;
        return kasa;
    }

    int wplacKaseAdamowi(int nowaKasa) {
        kasa += nowaKasa;

    }

};


class Bartek {

public:
    void setKasa(Adam* obiekt, int nowaWartosc)
    {
        obiekt->kasa = nowaWartosc;
    }

    void dodaj(Adam* obiekt, int wartosc)
    {
        obiekt->wplacKaseAdamowi(wartosc);
    }


};


class Czarek {

public:

    void setKasa(Adam* obiekt, int nowaWartosc)
    {
        //obiekt->kasa = nowaWartosc;
        cout << "puste wywolanie" << endl;
    }

    void dodaj(Adam* obiekt, int wartosc)
    {
        obiekt->wplacKaseAdamowi(wartosc);
    }

    void przywitajSie(Adam* obiekt, string komunikat)
    {
        cout << komunikat << " " << obiekt->nazwa << endl;

    }

};




int main()
{
    cout << "Klasy zaprzyjaznione!" << endl;

    Adam* a = new Adam();
    Bartek* b = new Bartek();
    Czarek* c = new Czarek();

    a->getKasa();
    b->setKasa(a, 15);

    a->getKasa();

    b->dodaj(a, 10);
    a->getKasa();

    c->dodaj(a, 100);
    a->getKasa();

    a->wplacKaseAdamowi(1000);
    a->getKasa();

    c->przywitajSie(a, "Witaj!" );


    return 0;
}
