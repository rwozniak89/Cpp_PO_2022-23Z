#include <iostream>
#include <time.h>
#include "MyList.h"
#include "MyClass.h"
#include <list>
#include <vector>
#include <algorithm>

using namespace std;


class MyBox
{
private:
    int valueInt;
    float valueFloat;

    vector<MyClass*> * box;

public:
    MyClass* testObject;

    MyBox()
    {
        valueInt = 0;
        valueFloat = 0.0;
        testObject = new MyClass();
        box = new vector<MyClass*>();
    }

    void addObjToBox(MyClass* newObj )
    {
        if(box->size() < 5 )
        {
           box->push_back(newObj);
            cout << "dodano obj do boxa" << endl;
        }
        else
        {
            cout << "brak miejsca w box" << endl;
        }

    }

    void printBox()
    {
        cout<< "Info o Box, valueInt:" << valueInt << ", valueFloat:" << valueFloat <<endl;
         for(auto i: *(this->box) ) {
            i->printData();
        }
        cout<< endl;
    }



};



bool larger(int a, int b){ return a> b;}

int main()
{
    cout << "RozneKolekcje" << endl;


    srand(time(0)); // Use current time as seed for random generator


    cout << endl << "########### " << "talica int tab[]"<< " ###########" << endl;

    int tab[10] = { 0 };
    int tabSize = sizeof(tab)/sizeof(int);
    cout << "#wyswietlanie tablicy" << endl;
    for(int i= 0; i <tabSize; i++)
    {
        cout << "["<< i << "]"<< tab[i] << " " ;
    }
    cout << endl;
    for(int i= 0; i <tabSize; i++)
    {
        tab[i] = 10 + i;
    }
    for(int i= 0; i <tabSize; i++)
    {
        cout << "["<< i << "]"<< tab[i] << " " ;
    }
    cout << endl;


    const int tab2Size = 10;
    int tab2[tab2Size]; // 10 elementów
    cout << "tab2: ";
    for(int i=0; i<tab2Size; i++)
    {
        cout<< tab2[i] << " " ;
    }
    cout<< endl;

    int tab3[10] = {1,2,3,4,5}; // 10 elementów
    cout << "tab3: ";
    for(int i=0; i<tab2Size; i++)
    {
        cout<< tab3[i] << " " ;
    }
    cout<< endl;

    cout << endl << "########### " << "MyList"<< " ###########" << endl;

    MyList* mojaLista = new MyList();
    cout << "#wyswietlanie mojej listy" << endl;
    mojaLista->printList();


    for(int i=0; i<5; i++)
    {
        int liczba = rand() % 10;
        mojaLista->addToEnd(liczba);
    }
    cout << "#wyswietlanie mojej listy" << endl;
    mojaLista->printList();


    cout << endl << "########### " << "list<int>"<< " ###########" << endl;

    list<int> my_list1 = { 12, 5, 10, 9 };
    list<int>* my_list2 = new list<int>( {1,2,3,4,5} );



//    for(int i=0; i< my_list1.size() ; i++)
//    {
//        cout << my_list1[i]
//    }
    cout << "#wyswietlanie list<int> za pomoca for oraz iterator" << endl;
    for (auto it = my_list1.cbegin(); it != my_list1.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;


    cout << "#wyswietlanie list<int>* za pomoca for oraz iterator" << endl;
    for (auto it = my_list2->cbegin(); it != my_list2->cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "#wyswietlanie list<int> za pomoca for each" << endl;
    for (int x : my_list1) {
		std::cout << x << " ";
	}
	cout << endl;

    cout << "#wyswietlanie list<int> za pomoca for each" << endl;
    for (int x : *my_list2) {
		std::cout << x << " ";
	}
	cout << endl;


	list<int>* my_list3 = new list<int>();
	my_list3->push_back(10);
    my_list3->push_back(20);
    my_list3->push_front(5);
    my_list3->push_back(30);

    cout << "#wyswietlanie list<int>* my_list3 za pomoca for each po dodaniu elementow do pustejlisty" << endl;
    for (int x : *my_list3) {
		std::cout << x << " ";
	}
	cout << endl;

    my_list3->remove(20);

    cout << "#wyswietlanie list<int>* my_list3 za pomoca for each po usunieciu 20" << endl;
    for (int x : *my_list3) {
		std::cout << x << " ";
	}
	cout << endl;

    my_list3->push_front(3);
    my_list3->push_front(2);
	my_list3->push_front(1);

	cout << "#wyswietlanie list<int>* my_list3 za pomoca for each po dodaniu elementow..." << endl;
    for (int x : *my_list3) {
		std::cout << x << " ";
	}
	cout << endl;

	 my_list3->reverse();

    cout << "#wyswietlanie list<int>* my_list3 za pomoca for each po reverse..." << endl;
    for (int x : *my_list3) {
		std::cout << x << " ";
	}
	cout << endl;


    cout << endl << "########### " << "vector"<< " ###########" << endl;

	vector<int> vectorTab;
    cout << "vectorTab: ";
    for(int i=0; i<vectorTab.size(); i++)
    {
        cout<< vectorTab[i] << " " ;
    }
    cout<< endl;

    vector<int> vectorTab2(3, -1);
    cout << "vectorTab2: ";
    for(int i=0; i<vectorTab2.size(); i++)
    {
        cout<< vectorTab2[i] << " " ;
    }
    cout<< endl;

    vector<int> vectorTab3 = { 1,2,3,4,5,6};
    cout << "vectorTab3: ";
    for(int i=0; i<vectorTab3.size(); i++)
    {
        cout<< vectorTab3[i] << " " ;
    }
    cout<< endl;

    vectorTab3.push_back(7);
    cout << "vectorTab3: ";
    for(int i=0; i<vectorTab3.size(); i++)
    {
        cout<< vectorTab3[i] << " " ;
    }
    cout<< endl;



    vector<int> vectorTab4 = { 8,-5,3,5,0,2};
    cout << "vectorTab4: ";
    for(int i=0; i<vectorTab4.size(); i++)
    {
        cout<< vectorTab4[i] << " " ;
    }
    cout<< endl;

    sort(vectorTab4.begin(), vectorTab4.end());
    sort(vectorTab4.begin(), vectorTab4.end(), greater<int>());


    sort(vectorTab4.begin(), vectorTab4.end(), larger);

    cout << "vectorTab4 (after sort): ";
    for(auto i: vectorTab4){
        cout << i << " ";
    }
    cout<< endl;
    for(int i=0; i<vectorTab4.size(); i++)
    {
        cout<< vectorTab4[i] << " " ;
    }
    cout<< endl;

    cout << "vectorTab4 find: ";
    //vector<int>::iterator it = find(vectorTab4.begin(), vectorTab4.end(), 0);
    auto it = find(vectorTab4.begin(), vectorTab4.end(), 0);
    if( it != vectorTab4.end()){
        cout << "item  found" << endl;
    }
    else{
        cout << "item not found" << endl;
    }

    cout << "#usuwanie elementu z vectora po wartosci z uzyciem find.." << endl;
    vector<int>::iterator position = std::find(vectorTab4.begin(), vectorTab4.end(), 5);
    if (position != vectorTab4.end()) // == myVector.end() means the element was not found
    vectorTab4.erase(position);

    cout << "vectorTab4 iterator for after erase1: ";
    for(auto it = vectorTab4.begin(); it != vectorTab4.end(); it++){
        cout<< *it << " ";
    }
    cout<< endl;

    cout << "#usuwanie elementu z vectora po wartosci z uzyciem remove.." << endl;
    /// wczeœniej wymaga #include <algorithm>
    vectorTab4.erase(std::remove(vectorTab4.begin(), vectorTab4.end(), 2), vectorTab4.end());
    cout << "vectorTab4 iterator for after erase1: ";
    for(auto it = vectorTab4.begin(); it != vectorTab4.end(); it++){
        cout<< *it << " ";
    }
    cout<< endl;

    cout << "#usuwanie elementu z vectora po wartosci z indexu-polozenia.." << endl;
    vectorTab4.erase(vectorTab4.begin() + 1);
    //vectorTab4.erase(vectorTab4.begin(), vectorTab4.end());
    cout << "vectorTab4 after erase3: ";
    for(auto it = vectorTab4.begin(); it != vectorTab4.end(); it++){
        cout<< *it << " ";
    }
    cout<< endl;

    vectorTab4.clear();
    cout << "vectorTab4 after clear: ";
    for(auto it = vectorTab4.begin(); it != vectorTab4.end(); it++){
        cout<< *it << " ";
    }
    cout<< endl;

    cout<< endl;

    cout << endl << "########### " << "Zastosowanie koleckji typu vector dla wlasnego typu danych (tutaj obiekt kalsy MyClass)"<< " ###########" << endl;


    vector<MyClass> v1;

    MyClass a1,b1,c1,d1;

    v1.push_back(a1);
    v1.push_back(b1);
    v1.push_back(c1);
    v1.push_back(d1);

    cout << "#wyswietlanie obiektow klasy z kolekcji" << endl;
    for(auto i: v1){
        cout << i.id << " ";
    }
    cout<< endl;


    vector<MyClass*> v2;

    MyClass* a = new MyClass(1);
    MyClass* b = new MyClass(2);
    MyClass* d = new MyClass();
    MyClass* c = new MyClass(3);

    v2.push_back(a);
    v2.push_back(b);
    v2.push_back(d);
    v2.push_back(c);

    cout << "#wyswietlanie obiektow klasy (* new) z kolekcji" << endl;
    for(auto i: v2){
        cout << i->id << " ";
    }
    cout<< endl;


    cout << "#wyswietlanie obiektow klasy (* new) z kolekcji (* new) z roznymi atrybutami" << endl;
    vector<MyClass*> * v3 = new vector<MyClass*>();

    MyClass* a3 = new MyClass(10);
    a3->valueInt = 11;
    a3->valueFloat = 11.1;
    a3->valueBool = true;

    MyClass* b3 = new MyClass(20);
    b3->valueInt = 21;
    b3->valueFloat = 21.1;
    b3->valueBool = false;

    MyClass* d3 = new MyClass();

    v3->push_back(a3);
    v3->push_back(b3);
    v3->push_back(d3);

    for(auto i: *v3){
        i->printData();
    }
    cout<< endl;


    cout << "#operacje na wlasnym box" << endl;

    MyBox* box = new MyBox();


    box->addObjToBox(a3);
    box->addObjToBox(b3);
    box->addObjToBox(a);
    box->addObjToBox(b);
    box->addObjToBox(c);
    box->addObjToBox(d);


    box->printBox();

    box->testObject->valueBool = true;


    return 0;
}
