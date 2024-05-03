#include "PhysicsManager.h"


void PhysicsManager::addObject(Physics* object) {
	objects.push_back(object);
}

void PhysicsManager::update() {

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->updatePhysics();
	}
}

void PhysicsManager::removeObject(Physics* object) {
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

PhysicsManager* physicsManager = nullptr;