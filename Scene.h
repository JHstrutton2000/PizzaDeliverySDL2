#ifndef Scene_H
#define Scene_H

#include "CollisionManager.h"
#include "QuestManager.h"
#include "RenderManager.h"
#include "PhysicsManager.h"
#include "InteractableManager.h"

class Scene {
public:
	Scene();
	void update();
	void render();

	CollisionManager* collisionManager;
	QuestManager* questManager;
	RenderManager* renderManager;
	PhysicsManager* physicsManager;
	InteractableManager* interactableManager;
};

#endif //Scene_H