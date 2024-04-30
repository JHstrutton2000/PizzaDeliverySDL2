#include "InteractableManager.h"

Physics* InteractableManager::nearestInteractable(Physics* object) {
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

void InteractableManager::addObject(Physics* object) {
	objects.push_back(object);
}

InteractableManager* interactableManager = nullptr;