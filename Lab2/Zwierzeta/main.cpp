#include <iostream>
#include "Organizm.h"
using namespace std;

int main()
{
    cout << "Hello world - Zwierzeta!" << endl;

    Organizm plankton("planktonoweDNA");
    plankton.przedstawSie();

    Organizm* wirus = new Organizm("covidus");
    wirus->przedstawSie();

    return 0;
}
