#include "MyList.h"

#include <iostream>

using namespace std;


int MyListElement::getKey()
{
	return this->key;
}

MyListElement::MyListElement(int key) {
	this->key = key;
	this->next = 0;
}

void MyList::addToBeginning(int key)
{
	MyListElement* newElement = new MyListElement(key);
	newElement->next = firstElement;
	firstElement = newElement;

}

void MyList::addToEnd(int key)
{
	MyListElement* newElement = new MyListElement(key);

	if (this->firstElement == 0) {
		this->firstElement = newElement;
	}
	else {
		MyListElement* temp = firstElement;

		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newElement;
		newElement->next = 0;
	}
}

bool MyList::contains(int key)
{
	MyListElement* temp = firstElement;
	while (temp) {
		if (temp->getKey() == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void MyList::removeKey(int key)
{
	MyListElement* temp = firstElement;
	MyListElement* prev = firstElement;
	while (temp) {
		if (temp->getKey() == key)
		{
			if (temp == firstElement) {
				firstElement = firstElement->next;
				delete temp;
				temp = firstElement;
				prev = firstElement;
			}
			else {
				prev->next = temp->next;
				delete temp;
				temp = prev->next;
			}

		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}
}

void MyList::clearAll()
{
	MyListElement* temp = firstElement;
	while (temp) {
		if (temp->next) {
			firstElement = temp->next;
			delete temp;
			temp = firstElement;
		}
		else {
			delete temp;
			temp = 0;
		}
	}
}

void MyList::printList()
{
	MyListElement* temp = firstElement;
	cout << "[";
	this->size = 0;
	while (temp) {
		if(temp != firstElement)
			cout << ", ";
		cout << temp->getKey();
		temp = temp->next;
		this->size++;
	}
	cout << "] size: " << this->size << endl;
}

void MyList::printListWithArrow()
{
	MyListElement* temp = firstElement;
	cout << "List: [";
	this->size = 0;
	while (temp) {
		if(temp != firstElement)
			cout << " -> ";
		cout << temp->getKey();
		temp = temp->next;
		this->size++;
	}
	cout << "] size: " << this->size << endl;
}


