#ifndef PhysicsManager_h
#define PhysicsManager_h

#include <SDL.h>
#include <vector>
#include "Physics.hpp"

class PhysicsManager{
public:
	void update();
	void removeObject(Physics* object);
	void addObject(Physics* object);
private:
	std::vector<Physics*> objects;
};

#endif //PhysicsManager_h