#ifndef GOD_H
#define GOD_H

//includes
#include "WinMgr.h"

//foward declarations
class Object;
class Agent;
class Camera;

class God{
	bool alive;
	bool redo;
	WinMgr window;
	Object *tHead;
	Object *terrain;
	Object *sHead;
	Object *selectable;
	Agent *rHead;
	Agent *robots;
	Camera *eye;

	God(const God& g); //there is no copying of God
	God& operator=(const God& g);

	void forgetAll();
	void generateTerrain();
	void setStartAgents();
	void issueMove(const Vector& dest);
	void attemptSelect();
	Vector getWorldCoord(int mx,int my);

	public:
	God(); //default constructor
	void newGame();
	void draw();
	void input();
};

#endif
