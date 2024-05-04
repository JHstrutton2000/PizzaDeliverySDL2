#include "Scene.h"

Scene::Scene(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Color* _color) {
	renderManager = new RenderManager(_window, _renderer, _color);
	interactableManager = new InteractableManager();
	collisionManager = new CollisionManager();
	physicsManager = new PhysicsManager();
	questManager = new QuestManager();
}

void Scene::update() {
	physicsManager->update();
	collisionManager->update();
}

void Scene::render() {
	renderManager->render();
}