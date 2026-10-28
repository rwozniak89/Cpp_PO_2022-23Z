#include <iostream>
#include "Organizm.h"
#include "Zwierze.h"
#include "Owca.h"
#include "WilkX.h"
using namespace std;

int main()
{
    cout << "############# Hello world - Zwierzeta!" << endl;

    Organizm plankton("planktonoweDNA");
    plankton.przedstawSie();

    Organizm* wirus = new Organizm("covidus");
    wirus->przedstawSie();
    delete wirus;

    cout << endl << "###############--- Zwierzeta ---" << endl;
    Zwierze zwierz("zwierzeceDNA", "Stworek");
    Owca dolly("owczeDNA", "Dolly", 4.5);
    WilkX wilk("wilczeDNA", "Szary", 2.0);

    // polimorfizm: wywolanie metod wirtualnych przez wskaznik na klase bazowa
    Zwierze* zwierzeta[] = { &zwierz, &dolly, &wilk };
    for (Zwierze* z : zwierzeta)
    {
        z->przedstawSie();
        z->dajGlos();
        cout << endl;
    }

    wilk.zjedzOwce(dolly);
    cout << "Wilk zjadl owiec: " << wilk.ileZjedzonychOwiec() << endl;

    cout << endl << "##############--- Zwierzeta tworzone przez new ---" << endl;

    Zwierze* zwierzak = new Zwierze("zwierzeceDNA2", "Potworek");
    Owca* owieczka = new Owca("owczeDNA2", "Shaun", 3.2);
    WilkX* wilczek = new WilkX("wilczeDNA2", "Bury", 1.5);

    // polimorfizm: wskazniki na klase bazowa do obiektow na stercie
    Zwierze* noweZwierzeta[] = { zwierzak, owieczka, wilczek };
    for (Zwierze* z : noweZwierzeta)
    {
        z->przedstawSie();
        z->dajGlos();
        cout << endl;
    }

    wilczek->zjedzOwce(*owieczka);
    wilczek->zjedzOwce(dolly);
    cout << "Wilk zjadl owiec: " << wilczek->ileZjedzonychOwiec() << endl;

    // wirtualny destruktor w Organizm gwarantuje poprawne zwolnienie
    // obiektu pochodnego nawet przez wskaznik na klase bazowa
    for (Zwierze* z : noweZwierzeta)
    {
        delete z;
    }



     cout << endl << "##############--- Zwierzeta tworzone przez new jako zwierze ---" << endl;

    Zwierze* zwierzak3 = new Zwierze("zwierzeceDNA3", "Potworek");
    Zwierze* owieczka3 = new Owca("owczeDNA3", "Owieczka", 3.2);
    Owca* wilczek3 = new WilkX("wilczeDNA3", "Wilczek", 1.5);

    // polimorfizm: wskazniki na klase bazowa do obiektow na stercie
    Zwierze* noweZwierzeta3[] = { zwierzak3, owieczka3, wilczek3 };
    for (Zwierze* z : noweZwierzeta3)
    {
        z->dajRyk();
        cout << endl;
    }

    //((Organizm*)wilczek3)->

    return 0;
}
