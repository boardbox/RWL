#ifndef ILINKEDLIST_H
#define ILINKEDLIST_H

class ILinkedList{
	ILinkedList *prev;
	ILinkedList *next;

	ILinkedList(const Object&);
	ILinkedList& operator=(const Object&);
	
	public:
	ILinkedList();
	ILinkedList* getNext() const;
	ILinkedList* getPrev() const;
	void setNext(ILinkedList *t);
	void setPrev(ILinkedList *t);
};

#endif
