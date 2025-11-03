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
        cout << "Kasa uzytkownika " << nazwa << " to: " << kasa << endl;
        return kasa;
    }

    int wplacKaseAdamowi(int nowaKasa) {
        cout << "Wplacono uzytkownikowi " << nazwa << "kwote: " << nowaKasa << endl;
        kasa += nowaKasa;

    }

};


class Bartek {

    string nazwa = "Bartek";

public:
    void setKasa(Adam* obiekt, int nowaWartosc)
    {
        obiekt->kasa = nowaWartosc;
        cout << this->nazwa << " ustalil wysokosc konta uzytkownika " << obiekt->nazwa << " na poziomie " << obiekt->kasa << endl;

    }

    void dodaj(Adam* obiekt, int wartosc)
    {
        obiekt->wplacKaseAdamowi(wartosc);
        cout << this->nazwa << " ustalil wysokosc konta uzytkownika " << obiekt->nazwa << " na poziomie " << obiekt->kasa << endl;

    }


};


class Czarek {

    string nazwa = "Czarek";

public:

    void setKasa(Adam* obiekt, int nowaWartosc)
    {
        //obiekt->kasa = nowaWartosc;
        cout << "puste wywolanie" << endl;
    }

    void dodaj(Adam* obiekt, int wartosc)
    {
        obiekt->wplacKaseAdamowi(wartosc);
        cout << this->nazwa << " ustalil wysokosc konta uzytkownika " << obiekt->nazwa << " na poziomie " << obiekt->getKasa() << endl;
        //cout << this->nazwa << "ustalil wysokosc konta uzytkownika " << obiekt->nazwa << " na poziomie " << obiekt->kasa << endl;
    }

    void przywitajSie(Adam* obiekt, string komunikat)
    {
        cout << this->nazwa  << " powiedzial: "<<komunikat << " do uzytkownika " << obiekt->nazwa << endl;

    }

};




int main()
{
    cout << "Klasy zaprzyjaznione!" << endl;

    cout << "Powolanie do zycia!" << endl;
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
