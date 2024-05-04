#include "InteractableManager.h"

Controllable* InteractableManager::nearestInteractable(Controllable* object) {
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] == object || !objects[i]->interactable() || objects[i]->disabled) {
			
		}
		else{
			float rads = objects[i]->getInteractRadius() + object->getInteractRadius();
			float* objCenter = object->getCenter();

			float distFromCenter = objects[i]->distanceFromCenter(objCenter);

			if (distFromCenter <= rads) {
				return objects[i];
			}
		}
	}

	return nullptr;
}

void InteractableManager::addObject(Controllable* object) {
	objects.push_back(object);
}
void InteractableManager::removeObject(Controllable* object) {
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}
