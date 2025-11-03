#include <iostream>

using namespace std;

//Utwórz klasê Pojazd
//z konstruktorami bezparametrowym i parametrowym
//z atrybutami (+nazwa, #vin, -rocznik),
//z metodami pokazaæ dostêpnoœæ:
//a)	+metodaPubliczna
//b)	#metodaChroniona
//c)	-metodaPrywatna
//+uzyjMetod() …. Publi, chron, prywat
//
//+dajSygnal()
//+dajSygnalZVirtual()



class Pojazd
{
public:
    string nazwa;
    int stanPaliwa;
    void metodaPubliczna(){
        cout << "Pojazd: metodaPubliczna" << endl;
    }

    void setNazwa(string nazwa){
        this->nazwa = nazwa;
    }

    Pojazd()
    {
        cout << "Pojazd: konstruktor Pojazd()" << endl;
    }

    Pojazd(string nazwa)
    {
        cout << "Pojazd: konstruktor Pojazd(string nazwa)" << endl;
        this->nazwa = nazwa;
    }

    void uzyjMetod(){
        cout << "Pojazd: uzyjMetod" << endl;
        metodaPubliczna();
        metodaChroniona();
        metodaPrywatna();
    }

    void dajSygnal(){
        cout << "Pojazd " << nazwa <<": dajSygnal: bipbip" << endl;
    }
    virtual void dajSygnalZVirtual(){
        cout << "Pojazd " << nazwa <<": dajSygnalZVirtual: bipbip " << endl;
    }

    void obslugaInkluzyjnaDoPorownywaniaNazw(Pojazd* pojazdDoPorowania){

        if(this->nazwa == pojazdDoPorowania->nazwa)
        {
            cout << "obslugaInkluzyjnaDoPorownywaniaNazw: Tak" << endl;
        }
        else
        {
             cout << "obslugaInkluzyjnaDoPorownywaniaNazw: Nie" << endl;
        }

    }



protected:
    string vin;
    void metodaChroniona(){
        cout << "Pojazd: metodaChroniona" << endl;
    }

private:
    int rocznik;
    void metodaPrywatna(){
        cout << "Pojazd: metodaPrywatna" << endl;
    }
};

class Silnik {

public:
    string nazwa;
    int pojemnosc;
    float poziomPaliwa;


    Silnik()
    {
        cout << "Silnik: konstruktor" << endl;
        nazwa = "silnik wersja 1";
        poziomPaliwa = 0.1;
    }

    Silnik(string nazwa)
    {
        cout << "Silnik: konstruktor Silnik(string nazwa)" << endl;
        this->nazwa = nazwa;
    }

    bool uruchomSilnik(){
        if(poziomPaliwa >= 0.1)
        {
            poziomPaliwa -= 0.1;
            cout << "Silnik " << nazwa <<": uruchomilem sie !" << endl;
            return true;
        }
        cout << "Silnik " << nazwa <<": brak paliwa!" << endl;
        return false;
    }
};

class SilnikElektryczny {

public:
    string nazwa;
    int pojemnosc;
    float poziomEnergii;


    SilnikElektryczny()
    {
        cout << "SilnikElektryczny: konstruktor" << endl;
        nazwa = "Silnik Elektro v1";
        poziomEnergii = 0.1;
    }

    SilnikElektryczny(string nazwa)
    {
        cout << "SilnikElektryczny: konstruktor SilnikElektryczny(string nazwa)" << endl;
        this->nazwa = nazwa;
    }

    bool obrotSilinika(){
        if(poziomEnergii >= 0.1)
        {
            poziomEnergii -= 0.1;
            cout << "SilnikElektryczny " << nazwa <<": obrocilem sie !" << endl;
            return true;
        }
        cout << "SilnikElektryczny " << nazwa <<": brak enegrii!" << endl;
        return false;
    }


    void zwiekszMocPojazdu()
    {

        cout << "moc zwiekszona!!!" << endl;
    }
};


class Samochod : public Pojazd, public Silnik {

public:
    string model;

    ////relacja 1 do 1 - agregacja/kompozycja
    //SilnikElektryczny silniczek;
    SilnikElektryczny* silniczek;
    /////relacja 1 do 2
    //SilnikElektryczny* silniczek2;
    //SilnikElektryczny* silniczek3;
    ////relacja 1 do n
    //Pojazd* tablica[] /// vecctor, list, wlasnaLista...


    Samochod()
    {
        cout << "Samochod: konstruktor" << endl;
        silniczek = new SilnikElektryczny();
    }

    Samochod(string model)
    {
        cout << "Samochod: konstruktor Samochod(string model)" << endl;
        this->model = model;
        silniczek = new SilnikElektryczny();
    }

    Samochod(string nazwa2, string model) : Pojazd(nazwa2)
    {
        cout << "Samochod: konstruktor Samochod(string nazwa2, string model) : Pojazd(nazwa2)" << endl;
        this->model = model;
        silniczek = new SilnikElektryczny();
    }

    void metodaPubliczna(){
        cout << "Samochod: metodaPubliczna" << endl;
    }

     void jedz(){
        bool czyMozeJechac = this->uruchomSilnik();
        if(czyMozeJechac){
            cout << "Samochod: jedzie" << endl;
        }
        else if (this->silniczek->obrotSilinika()) {
            cout << "Samochod: jedzie na pradzie" << endl;
        }

        else {
            cout << "Samochod: kompletnie stoi" << endl;
        }

    }



    void dajSygnal(){
        cout << "Samochod " << Pojazd::nazwa <<": dajSygnal: brumbrum" << endl;
    }
    void dajSygnalZVirtual(){
        cout << "Samochod " << Pojazd::nazwa <<": dajSygnalZVirtual: brumbrum " << endl;
    }


};




int main()
{
    cout << "Dziedziczenie - Polimorfiz!" << endl;

    cout << "############ Pojazd" << endl<< endl;
    Pojazd* a = new Pojazd("Fiacik"); /// Pojazd a;
    //a->setNazwa("Fiat");
    a->metodaPubliczna();
    //a->metodaChroniona();
    //a->metodaPrywatna();
    a->uzyjMetod();
    a->dajSygnal();
    a->dajSygnalZVirtual();

    cout << "############ Samochod" << endl<< endl;
    Samochod* samochod = new Samochod("Form Mondeo");
    //samochod->setNazwa("samochod 1");
    samochod->metodaPubliczna();
    samochod->jedz();
    //samochod->jedz();
    //samochod->jedz();
    //samochod->jedz();
    samochod->dajSygnal();
    samochod->dajSygnalZVirtual();


    //cout << "############ Samochod jako Pojazd" << endl<< endl;
    //wywo³anie metody dla referencji spowoduje zachowanie odpowiednie dla pe³nego typu obiektu wywo³ywanego
    Pojazd* samochod2 = new Samochod("samochod nr2", "Opel Astra");
    ////samochod2->setNazwa("samochod 2");
    //samochod2->metodaPubliczna();
    //((Samochod*)samochod2)->jedz();
    ////samochod2->jedz();
    samochod2->dajSygnal();
    samochod2->dajSygnalZVirtual();
    ((Samochod*)samochod2) ->dajSygnal();


    //samochod->uruchomSilnik();
    //samochod->silniczek->zwiekszMocPojazdu();


    //a->
    //a->obslugaInkluzyjnaDoPorownywaniaNazw(a);
    //a->obslugaInkluzyjnaDoPorownywaniaNazw(samochod);
    //a->obslugaInkluzyjnaDoPorownywaniaNazw(samochod2);
    ////samochod2->setNazwa("a");
    ////samochod->setNazwa("a");
    //samochod->obslugaInkluzyjnaDoPorownywaniaNazw(samochod2);
/*

    Pojazd* tablica[] = { a, samochod, samochod2 };
    for(int i=0; i<3; i++)
    {
        tablica[i]->nazwa;
        tablica[i]->dajSygnal();
        tablica[i]->dajSygnalZVirtual();
    }

    Samochod* tablica2[] = { (Samochod*)a, samochod, (Samochod*)samochod2 };
    for(int i=0; i<3; i++)
    {
        tablica2[i]->Pojazd::nazwa;
        tablica2[i]->dajSygnal();
        tablica2[i]->dajSygnalZVirtual();
    }
*/

    return 0;
}
