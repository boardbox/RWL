#include <cstdlib>
#include "ILinkedList.h"

ILinkedList::ILinkedList():prev(NULL),next(NULL){};

ILinkedList* ILinkedList::getNext() const{
	return next;
}

ILinkedList* ILinkedList::getPrev() const{
	return prev;
}

void ILinkedList::setNext(ILinkedList *t){
	next = t;
}

void ILinkedList::setPrev(ILinkedList *t){
	prev = t;
}
