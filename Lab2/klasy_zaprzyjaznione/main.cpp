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
        this->kasa += nowaKasa;

    }

};


class Bartek {
//friend class Adam;
    string nazwa = "Bartek";

public:
    void setKasa(Adam* obiekt, int nowaWartosc)
    {
        obiekt->kasa = nowaWartosc;
        cout << this->nazwa << " ustalil wysokosc konta uzytkownika " << obiekt->nazwa << " na poziomie " << obiekt->kasa << endl;

    }

    void dodaj(Adam* obiekt, int wartosc)
    {
        //obiekt->kasa += wartosc;
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
        //obiekt->wplacKaseAdamowi(wartosc);
        //cout << this->nazwa << " ustalil wysokosc konta uzytkownika " << obiekt->nazwa << " na poziomie " << obiekt->getKasa() << endl;
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
    Adam* adam  = new Adam();
    Bartek* bartek = new Bartek();
    Czarek* c = new Czarek();


    adam->getKasa();
    bartek->setKasa(adam, 15);

    adam->getKasa();
    cout << "wplata od Bartka" << endl;
    bartek->dodaj(adam, 10);
    cout << "wplata od Bartka2" << endl;
    adam->getKasa();

    //cout << "wplata od Czarka" << endl;
    //c->dodaj(adam, 100);
    //adam->getKasa();

    //adam->wplacKaseAdamowi(1000);
    //adam->getKasa();

    //c->przywitajSie(adam, "Witaj!" );


    return 0;
}
