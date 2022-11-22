#include "ListElement.h"

int ListElement::getKey()
{
	return this->key;
}

ListElement::ListElement(int key) {
	this->key = key;
	this->next = 0;
}

