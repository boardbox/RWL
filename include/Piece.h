#ifndef PIECE_H
#define PIECE_H

#include "ILinkedList.h"	//inherits
#include "Vector.h"			//has a

struct DrawData;				//has a pointer to a

class Piece : public ILinkedList{
	Vector loc;
	DrawData* dd;

	public:
	Piece();
	Piece(DrawData* d);
	Piece(DrawData* d,const Vector& loc);
	void draw();
};

#endif
