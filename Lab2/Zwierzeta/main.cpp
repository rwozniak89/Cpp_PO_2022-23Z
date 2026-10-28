#include <iostream>
#include "Organizm.h"
#include "Zwierze.h"
#include "Owca.h"
#include "WilkX.h"
using namespace std;

int main()
{
    cout << "Hello world - Zwierzeta!" << endl;

    Organizm plankton("planktonoweDNA");
    plankton.przedstawSie();

    Organizm* wirus = new Organizm("covidus");
    wirus->przedstawSie();
    delete wirus;

    cout << endl << "--- Zwierzeta ---" << endl;

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

    return 0;
}
