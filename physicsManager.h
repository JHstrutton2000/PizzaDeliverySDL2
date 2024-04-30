#include <SDL.h>
#include <vector>
#include "Physics.hpp"

class PhysicsManager{
public:
	PhysicsManager();
	~PhysicsManager();

	void update();
	void addObject(Physics* object);
private:
	std::vector<Physics*> objects;
};

extern PhysicsManager* physicsManager;