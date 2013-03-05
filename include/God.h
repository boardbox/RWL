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
	Agent *selection;
	Object *rHead;
	Object *robots;
	Camera *eye;

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
