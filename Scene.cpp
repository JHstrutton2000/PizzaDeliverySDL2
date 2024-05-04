#include "Scene.h"

Scene::Scene() {
	interactableManager = new InteractableManager();
	collisionManager = new CollisionManager();
	questManager = new QuestManager();
	renderManager = new RenderManager();
	physicsManager = new PhysicsManager();
}

void Scene::update() {
	physicsManager->update();
	collisionManager->update();
}

void Scene::render() {
	renderManager->render();
}