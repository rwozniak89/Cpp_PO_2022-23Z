#include <iostream>
#include <time.h>
#include <unistd.h>


#include "Class Model/Postac.h"

#include "Class Model/Przedmiot.h"

using namespace std;


int main()
{
    srand(time(NULL));

    cout << "PostacieLab5!" << endl;


    Postac* postac1 = new Postac("Zbyszek", 5, 4, 20, 1);
    postac1->przedstawSie();
    postac1->PokazStatystykiPostaci();

    Przedmiot* p1 = new Przedmiot("lina", 1);
    Przedmiot* p2 = new Przedmiot("pierscien", 1000);
    Przedmiot* p3 = new Przedmiot("pasek", 20);
    Przedmiot* p4 = new Przedmiot("buty", 30);

    postac1->dodajDoPlecaka(p1);
    postac1->dodajDoPlecaka(p2);
    postac1->dodajDoPlecaka(p3);
    postac1->dodajDoPlecaka(p4);

    postac1->wyswietlPlecak();


    cout << "\n##################" << endl;

    Postac* postac2 = new Postac("Piotrek", 6, 5, 22, 2);


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
    int licznikRund =1;
    while(postac1->czyZyje() && postac2->czyZyje())
    {
        //sleep(1);
        cout<< "runda: " << licznikRund << endl;
        postac1->zaatakuj(postac2);
        postac2->zaatakuj(postac1);

        licznikRund++;
    }


    cout<< "WYGRYWA: ";
    if(postac1->czyZyje()){
        cout << postac1->pobierzNazwe();
    }
    else  if(postac2->czyZyje()){
        cout << postac2->pobierzNazwe();
    }
    cout<< endl;



    return 0;
}
