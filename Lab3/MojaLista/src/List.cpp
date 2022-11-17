#include "List.h"

#include <iostream>

using namespace std;

void List::addToBeginning(int key)
{
	ListElement* newElement = new ListElement(key);
	newElement->next = firstElement;
	firstElement = newElement;

}

void List::addToEnd(int key)
{
	ListElement* newElement = new ListElement(key);

	if (this->firstElement == 0) {
		this->firstElement = newElement;
	}
	else {
		ListElement* temp = firstElement;

		while (temp->next) {
			temp = temp->next;
		}
		temp->next = newElement;
		newElement->next = 0;
	}
}

bool List::contains(int key)
{
	ListElement* temp = firstElement;
	while (temp) {
		if (temp->getKey() == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void List::removeKey(int key)
{
	ListElement* temp = firstElement;
	ListElement* prev = firstElement;
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


void List::printList()
{
	ListElement* temp = firstElement;
	cout << "[";
	this->size = 0;
	while (temp) {
		if(temp != firstElement )
			cout << ", ";
		cout << temp->getKey();
		temp = temp->next;
		this->size++;
	}
	cout << "] size: " << this->size << endl;
}

