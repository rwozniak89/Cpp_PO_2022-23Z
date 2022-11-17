#ifndef LISTELEMENT_H
#define LISTELEMENT_H


class ListElement
{
private:
	int key;
	ListElement* next;
public:
	int getKey();
	ListElement(int key);
	friend class List;
};

#endif // LISTELEMENT_H
