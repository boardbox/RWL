#include <cmath>
#include "Vector.h"
#include "Object.h"
#include "Agent.h"

const double speed = 10;
const double ftime = 0.01666667;

void Agent::move(){
	if(dest == loc) return; //nothing to do

	Vector dir(dest); //copy because subtract acts on callee
	dir.subtract(loc);

	double maxd = speed * ftime;
	if(dir.length() <= maxd){ //can move past target
		loc = dest;
		return;
	}

	dir.normalize();
	dir.x = dir.x * maxd;
	dir.y = dir.y * maxd;
	dir.z = dir.z * maxd;
	loc.add(dir);
	return;
}
