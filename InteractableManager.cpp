#include "InteractableManager.h"

Controllable* InteractableManager::nearestInteractable(Controllable* object) {
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

void InteractableManager::addObject(Controllable* object) {
	objects.push_back(object);
}

InteractableManager* interactableManager = nullptr;