#include <cstdlib>
#include "Vector.h"
#include "ILinkedList.h"
#include "Piece.h"

Piece::Piece():ILinkedList(),loc(Vector(0,0,-1000)),dd(NULL){}

Piece::Piece(DrawData* d):ILinkedList(),loc(Vector(0,0,-1000)),dd(d){}

Piece::Piece(DrawData* d,const Vector& l):ILinkedList(),loc(l),dd(d){}

void Piece::draw(){
	//draw logic would go here
}
