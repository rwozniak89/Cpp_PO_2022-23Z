///////////////////////////////////////////////////////////
//  Postac.cpp
//  Implementation of the Class Postac
//  Created on:      30-lis-2022 17:20:18
//  Original author: Radek
///////////////////////////////////////////////////////////

#include "Postac.h"

#include "Czarodziej.h"
//nclude "rodzajPrzedmiotu.h"

Postac::Postac(){

}



Postac::~Postac(){

}





Postac::Postac(string nazwa, int pktAtakuMax, int pktAtakuMin, int pktZycia, int poziom){

    this->plecak = new Plecak();
    this->rekaLewa = NULL;
    this->rekaPrawa = NULL;

    this->nazwa = nazwa;
    this->pktAtakuMax = pktAtakuMax;
    this->pktAtakuMin = pktAtakuMin;
    this->pktZycia = pktZycia;
    this->poziom = poziom;
}

string  Postac::pobierzNazwe(){
    return nazwa;
}

bool Postac::czyZyje(){

//    if(this->pktZycia > 0)
//    {
//        return true;
//    }
//    return false;

//    return (this->pktZycia > 0) ? true : false;
    return (this->pktZycia > 0);
}


void Postac::dodajDoPlecaka(Przedmiot* p){

    plecak->dodaj(p);

}





void Postac::PokazStatystykiPostaci(){

    cout << "###(P)" << this->nazwa
    << " (Statystyki): pktAtakuMax: " << this->pktAtakuMax
     << ", pktAtakuMin: " << this->pktAtakuMin
      << ", pktZycia: " << this->pktZycia
       << ", poziom: " << this->poziom
       <<endl;
}


void Postac::przedstawSie(){

    cout <<this->nazwa << ": " <<  generujPrzywitanie() << ", jestem " << this->nazwa  << "!"<<endl;

}

string Postac::generujPrzywitanie(){

    string tablica[] = { "Dzien dobry", "Witaj", "Ahoj", "Czesc", "Guten tag..." };
    int rozmiarTablicy = sizeof(tablica)/sizeof(string);

    int liczbaLosowa = rand() % rozmiarTablicy;

    return tablica[liczbaLosowa];
}

void Postac::zaatakuj(Postac* przeciwnik){

    cout <<this->nazwa << ": "<< "Rozpoczyna atak na przeciwnika " << przeciwnik->nazwa << " !" << endl;


    if( czyTrafion(przeciwnik->poziom) )//if(czyTrafion(przeciwnik->poziom) == true)
    {
        int obrazenia = obliczPktAtaku();
        if(rand() % 2 == 0){
            obrazenia += atakZaawansowany();
        }
        przeciwnik->przyjmijObrazenia(obrazenia);
    }
    else
    {
        cout <<"%%%" <<this->nazwa << ": "<< "PUDLO !!!" << przeciwnik->nazwa << " !" << endl;
    }

    cout <<this->nazwa << ": "<< "Konczy atak na przeciwnika " << przeciwnik->nazwa << " !" << endl;
}

int Postac::obliczPktAtaku(){

    cout<< this->nazwa << ": "<< "Uzywa ataku podstawowego" << endl;

    int sumaPkt = 0;

    int maxValue = this->pktAtakuMax;
    int minValue = this->pktAtakuMin;
    sumaPkt += minValue + (rand() % (maxValue - minValue));

    if(rekaLewa != NULL)
    {
        //if(rekaLewa->typ1 == 1)
        //if(rekaLewa->typ2 == rodzajPrzedmiotu.bron)
         //to use dynamic_cast<Bron*>(rekaPrawa)) add-make A polymorphic, which you can do by adding a virtual destructor or any virtual function:
        if(auto* przedmiotBron = dynamic_cast<Bron*>(rekaLewa))
        {
            maxValue = przedmiotBron->atakMax;
            minValue = przedmiotBron->atakMin;
            sumaPkt += minValue + (rand() % (maxValue - minValue));
        }
    }

    if(rekaPrawa != NULL)
    {
        if(rekaPrawa->typ2 == rodzajPrzedmiotu::bron)
        {
            maxValue = ((Bron*)rekaPrawa)->atakMax;
            minValue = ((Bron*)rekaPrawa)->atakMin;
            sumaPkt += minValue + (rand() % (maxValue - minValue));
        }
    }

    cout << "###" << this->nazwa << ": wygenerowano pktAtaku: " << sumaPkt << endl;
    return sumaPkt;

}

void Postac::przyjmijObrazenia(int pktObrazen){

    cout <<this->nazwa << ": "<< "przyjmuje liczbe obrazen: " << pktObrazen << " !" << endl;
    this->pktZycia -= pktObrazen;

    if(this->pktZycia < 0){
        this->pktZycia = 0;
    }

    this->PokazStatystykiPostaci();
}


void Postac::przywitajSieZInnaOsoba(Postac* osoba){

    cout <<this->nazwa << ": "<< "Witam Ciebie " << osoba->nazwa << " ;)" << endl;

}


void Postac::ustawBronLewa(Przedmiot* przedmiot){

    this->rekaLewa = przedmiot;
    cout <<this->nazwa << ": "<< "rekaLewa ustawiono :";
    przedmiot->OpiszSie();

}


void Postac::ustawBronPrawa(Przedmiot* przedmiot){

    this->rekaPrawa = przedmiot;
    cout <<this->nazwa << ": "<< " rekaPrawa ustawiono :";
    przedmiot->OpiszSie();
}


void Postac::wyswietlPlecak(){
    plecak->wyswietl();

    cout<< this->nazwa << ": koniec wyswietlania plecaka!" <<endl;
}





void Postac::zaprosDoWalki(Postac* osoba){
    //potrzaebna klasa Ring, metody dodaj¹ce postacie do kolekcji w ringu, metoda przyjmujaca zaproszenie do walki...
     cout <<this->nazwa << ": "<< "Zapraszam Ciebie " << osoba->nazwa << " do walki !!!! Statystyki: " << endl;
     this->PokazStatystykiPostaci();
     osoba->PokazStatystykiPostaci();
}



int Postac::atakZaawansowany()
{
    cout <<this->nazwa << ": "<< "Brak ataku zaawansowanego - to jest podstawowa kalsa Postac" << endl;
    return 0;

}

bool Postac::czyTrafion(int poziomPrzeciwnika){

        int los = (rand() % 100) + 1;

        if(this->poziom > poziomPrzeciwnika && los >= 25){
            return true;
        }
        else if(this->poziom == poziomPrzeciwnika && los >= 50){
            return true;
        }
        else if(this->poziom < poziomPrzeciwnika && los >= 66){
            return true;
        }
        return false;
}

int Postac::losuj(int minValue, int maxValue){
    return minValue + (rand() % (maxValue - minValue + 1));
}

Postac* Postac::generujPostac(){

    cout << "$$$$$$$$ Generowanie Postaci - metoda fabrykujaca" << endl;

    //(string nazwa, int pktAtakuMax, int pktAtakuMin, int pktZycia, int poziom){
    //losowanie paramerow..

    int pktZycia = losuj(50,200);
    int poziom = losuj(1,4);
    int pktAtakuMin = losuj(1,3);
    int pktAtakuMax = losuj(3,5);


    int losujKlase = losuj(1,2);
    Postac* postac = NULL;
    if(losujKlase == 1){
        cout << "GENERATOR: " << "wylosowano klase Postac" << endl;
        string nazwa = "PostacX:" + to_string(losuj(1,100000));
        postac = new Postac(nazwa, pktAtakuMax,  pktAtakuMin,  pktZycia, poziom);
    }
    else if(losujKlase == 2){
        cout << "GENERATOR: " << "wylosowano klase Czarodzieja" << endl;
        string nazwa = "CzarodziejX:" + to_string(losuj(1,100000));
        int mana = losuj(1,5);
        postac = new Czarodziej(nazwa, pktAtakuMax,  pktAtakuMin,  pktZycia, poziom, mana);
    }
    else
    {
        cout << "GENERATOR: " << "Blad generatora brak takiej klasy" << endl;
        return NULL;
    }

     ///tutaj wykorzystanie metody fabrykujace bron...
     //postac->rekaLewa = metoda fabrykujaca bron....
     int losujBron = losuj(1,3);
     cout << "GENERATOR: " << "losujBron: " << losujBron << endl;
     if(losujBron == 1)
     {

        //losuje pierwsza bron
        //metoda fabrykujaca bron....
         string nazwa = "MieczX:" + to_string(losuj(1,100));
        int cena = losuj(1,200);
        int atakMin = losuj(1,4);
        int atakMax = losuj(4,15);
        int obrona = losuj(1,5);
        int wytrzymalosc = losuj(1,100);
        Przedmiot* p = new Bron(nazwa, cena, atakMin, atakMax, obrona, wytrzymalosc);
        postac->ustawBronPrawa(p);
     }

     if(losujBron <= 2)
     {
         //losuje druga bronie
         //metoda fabrykujaca bron....
         string nazwa = "ToporX:" + to_string(losuj(1,100));
        int cena = losuj(1,200);
        int atakMin = losuj(1,4);
        int atakMax = losuj(4,15);
        int obrona = losuj(1,5);
        int wytrzymalosc = losuj(1,100);
        Przedmiot* p = new Bron(nazwa, cena, atakMin, atakMax, obrona, wytrzymalosc);
        postac->ustawBronLewa(p);
     }



    return postac;


}

