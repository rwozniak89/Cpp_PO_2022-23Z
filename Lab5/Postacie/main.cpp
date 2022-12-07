#include <iostream>

#include "Class Model/Postac.h"

#include "Class Model/Przedmiot.h"

using namespace std;


int main()
{
    cout << "PostacieLab4!" << endl;


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





    return 0;
}
