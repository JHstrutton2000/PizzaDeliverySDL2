#include "PhysicsManager.h"


void PhysicsManager::addObject(Physics* object) {
	objects.push_back(object);
}

void PhysicsManager::update() {

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->updatePhysics();
	}
}

PhysicsManager* physicsManager = nullptr;