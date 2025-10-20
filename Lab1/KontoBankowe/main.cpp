#include <iostream>

using namespace std;


class Konto{

private:
    int stan = 0;
    string waluta;

public:
    int pobierzStan()
    {
        return stan;
    }
    void wyswietlStan()
    {

        cout << "stan konta: " << stan << " " << waluta << "\n"; //endl();
    }

    Konto(int poczatkowyStan, int kieszonkoweOdBabci){
        this->stan = poczatkowyStan + kieszonkoweOdBabci;
    };

    Konto(int stan){
        stan = stan;
    };

    Konto(string waluta){
        waluta = waluta;
    };

    Konto(){
        stan = 500;
        waluta = "PLN";
    };

    void wplac(int x)
    {
        if (x > 0)
        {
            stan = stan + x; // stan += x;
            cout << "wplacono " << x << endl;
            return;
        }
        //else {
        cout << "kwota mniejsza lub rowna 0, brak wplaty!!!" << endl;
        //}
    }

    int wyplac(int x)
    {
        if( x > 0 ) //&& x < stan){
        {
            if(x <= stan)
            {
                stan = stan - x;
                cout << "wyplacono " << x << endl;
                return x;
            }
        }

        cout << "kwota mniejsza lub rowna 0 lub mniejsza niz stan konta, brak wyplaty!!!" << endl;
        return 0;
    }


};

int main()
{
    cout << "Konto Bankowe teleBanku" << endl;


    Konto rachunekBankowy1;

    int pobranyStan = rachunekBankowy1.pobierzStan();
    cout << pobranyStan <<endl;
    rachunekBankowy1.wyswietlStan();

    Konto rachunekBankowy2(500, 1000);
    rachunekBankowy2.wyswietlStan();

    rachunekBankowy2.wyplac(2000);
    rachunekBankowy2.wyswietlStan();

    rachunekBankowy2.wplac(500);
    rachunekBankowy2.wyswietlStan();

    rachunekBankowy2.wyplac(2000);
    rachunekBankowy2.wyswietlStan();

    return 0;
}
