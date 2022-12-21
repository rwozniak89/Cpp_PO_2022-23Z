#include <stdio.h>
#include <stdlib.h>
char* wyswietl(char tab[],int n)
{
    char wynik;
    for(int i=0;i<n;i++)
    {
        wynik+=tab[i];
    }

    return wynik;

}
int main()
{
    int num=7;
    char tab[]={'M','a','r','c','i','n','_','M','i','l','u','n','s','k','i'};
    int dlg=15;
    if(num>15 || num<0)
    {
        num=15;
    }
    char tab2=wyswietl(tab[15],num);
    printf("%s",tab2);
    return 0;
}
