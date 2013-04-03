#ifndef GOD_H
#define GOD_H

//includes
#include "WinMgr.h"

//foward declarations
class Terrain;
class ILinkedList;
class Piece;

class God{
	bool alive;
	bool redo;
	WinMgr window;
	Terrain *tHead;
	Terrain *terrain;
	ILinkedList *rHead;
	ILinkedList *robots;
	Camera *eye;
	Piece* p1master;
	Piece* p2master;
	Piece* wmaster;
	Piece* p1head;
	Piece* p2head;
	Piece* whead;

	God(const God& g); //there is no copying of God
	God& operator=(const God& g);

	void forgetAll();
	void generateTerrain();
	void setStartAgents();
	void issueMove(const Vector& dest);
	void attemptSelect(const Vector&);

	Vector getWorldCoord(int mx,int my);

	public:
	God(); //default constructor
	void newGame();
	void draw();
	void input();
	void action();
};

#endif
