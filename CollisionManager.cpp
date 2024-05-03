#include "CollisionManager.h"

void CollisionManager::addObject(Collider* object)
{
	objects.push_back(object);
}

void CollisionManager::update()
{
	for (int i = 0; i < objects.size(); i++) {
		for (int j = 0; j < objects.size(); j++) {
			if (i != j) {
				objects[i]->colliding(objects[j]);
			}
		}
	}
}

CollisionManager* collisionManager = nullptr;
