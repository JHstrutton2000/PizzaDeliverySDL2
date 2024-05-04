#ifndef Scene_H
#define Scene_H

#include "CollisionManager.h"
#include "QuestManager.h"
#include "RenderManager.h"
#include "PhysicsManager.h"
#include "InteractableManager.h"

class Scene {
public:
	Scene(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Color* _color = new SDL_Color{ 0x00, 0x50, 0x00, 0x00 });
	void update();
	void render();

	CollisionManager* collisionManager;
	QuestManager* questManager;
	RenderManager* renderManager;
	PhysicsManager* physicsManager;
	InteractableManager* interactableManager;
};

#endif //Scene_H