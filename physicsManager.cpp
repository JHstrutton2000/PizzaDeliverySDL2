#include "PhysicsManager.h"

PhysicsManager::PhysicsManager() {

}

PhysicsManager::~PhysicsManager() {

}

void PhysicsManager::addObject(Physics* object) {
	objects.push_back(object);
}

void PhysicsManager::update() {

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->updatePhysics();
	}
}

Physics* PhysicsManager::nearestInteractable(Physics* object) {
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] == object || !objects[i]->interactable() || objects[i]->disabled) {
			continue;
		}

		if (objects[i]->distance(object->getPosition()) <= 50) {
			return objects[i];
		}
	}

	return nullptr;
}

PhysicsManager* physicsManager = nullptr;