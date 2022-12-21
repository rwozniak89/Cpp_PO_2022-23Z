#include <iostream>
#include <time.h>
//#include <unistd.h>


#include "Class Model/Postac.h"
#include "Class Model/Czarodziej.h"

#include "Class Model/Przedmiot.h"

using namespace std;


int main()
{
    srand(time(NULL));

    cout << "PostacieLab5!" << endl;


    Postac* postac1 = new Postac("Zbyszek", 5, 4, 100, 1);
    postac1->przedstawSie();
    postac1->PokazStatystykiPostaci();

    Przedmiot* p1 = new Przedmiot("lina", 1);
    Przedmiot* p2 = new Przedmiot("pierscien", 1000);
    Przedmiot* p3 = new Przedmiot("pasek", 20);
    Przedmiot* p4 = new Przedmiot("buty", 30);

    postac1->dodajDoPlecaka(p1);
    postac1->dodajDoPlecaka(p2);
    //postac1->dodajDoPlecaka(p3);
    //postac1->dodajDoPlecaka(p4);

    //postac1->wyswietlPlecak();

    cout << "\nPRzedmioty i bron##################" << endl;


    Przedmiot* b1 = new Bron("Miecz", 100, 8, 10, 1, 100);
    Przedmiot* b2 = new Bron("Topor", 100, 6, 12, 1, 100);
    Przedmiot* b3 = new Bron("Katana", 100, 1, 14, 1, 100);
    Przedmiot* b4 = new Bron("TarczaMala", 100, 2, 3, 5, 100);
    Przedmiot* b5 = new Bron("TarczaDuza", 100, 1, 4, 6, 100);
    //Bron* b6 = new Bron("Miecz2", 100, 8, 10, 1, 100);

    //postac1->dodajDoPlecaka(b6);
    postac1->dodajDoPlecaka(b1);
    postac1->wyswietlPlecak();

    //bron traktowana jako przemiot //brak virtual
    b1->OpiszSie();
    //bron traktowana jako bron ----
    Bron* b1a = (Bron*)b1;
    ((Bron*)b1)->OpiszSie();
    b1a->OpiszSie();

    vector<Przedmiot*> lista1;
    lista1.push_back(b1);
    lista1.push_back(b2);
    lista1.push_back(b3);
    lista1.push_back(b4);
    lista1.push_back(b5);
    for(int i=0; i< lista1.size(); i++)
    {
        lista1[i]->OpiszSie();
    }

    postac1->ustawBronLewa(b1);
    postac1->ustawBronPrawa(p2);



    cout << "\nWalka##################" << endl;

    Postac* postac2 = new Czarodziej("Magik", 6, 5, 80, 2, 5);
    postac2->ustawBronLewa(b2);
    postac2->ustawBronPrawa(p3);

    postac1->przedstawSie();
    postac2->przedstawSie();
    postac1->przywitajSieZInnaOsoba(postac2);
    postac2->przywitajSieZInnaOsoba(postac1);
    postac1->zaprosDoWalki(postac2);

//    postac1->zaatakuj(postac2);
//    postac2->zaatakuj(postac1);
//
//    postac1->zaatakuj(postac2);
//    postac2->zaatakuj(postac1);

    cout<< endl << "GENEROWANIE POSTACI I WALKA" << endl;

    //metody fabrykujace, mozna podawac paramtey od uzytkonika....
    postac1 = Postac::generujPostac();
    postac2 = Postac::generujPostac();


    postac1->wyswietlPlecak();
    postac2->wyswietlPlecak();

    int licznikRund =1;
    while(postac1->czyZyje() && postac2->czyZyje())
    {
        //sleep(1);
        cout<< "runda: " << licznikRund << endl;

        int los = rand() % 2;
        if(los == 0)
        {
            postac1->zaatakuj(postac2);
            if(postac2->czyZyje())
            {
                postac2->zaatakuj(postac1);
            }
        }
        else{
            postac2->zaatakuj(postac1);
            if(postac1->czyZyje())
            {
                postac1->zaatakuj(postac2);
            }
        }




        licznikRund++;
    }


    cout<< "WYGRYWA: ";
    if(postac1->czyZyje()){
        cout << postac1->pobierzNazwe();
    }
    else if(postac2->czyZyje()){
        cout << postac2->pobierzNazwe();
    }
    cout<< endl;



    return 0;
}
