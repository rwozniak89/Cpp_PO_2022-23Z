#ifndef MYLIST_H
#define MYLIST_H

class MyListElement
{
private:
	int key;
	MyListElement* next;
public:
	int getKey();
	MyListElement(int key);
	friend class MyList;
};


class MyList {
private:
	MyListElement* firstElement;
	int size;
public:
	void addToBeginning(int key);
	void addToBeginning(MyListElement* element);
	void addToEnd(int key);
	void addToEnd(MyListElement* element);
	MyListElement* getElement(int key);
	bool contains(int key);
	void removeKey(int key);
	void clearAll();
	void printList();
	void printListWithArrow();
	friend class MyListElement;
};


#endif // MYLIST_H
