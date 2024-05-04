#include "SceneManager.h"

void SceneManager::setActiveScene(Scene* scene) {
	activeScene = scene;
}

void SceneManager::update() {
	if (activeScene) {
		activeScene->update();
	}
}

void SceneManager::render() {
	if (activeScene) {
		activeScene->render();
	}
}

Scene* SceneManager::getActiveScene() {
	return activeScene;
}

SceneManager* sceneManager = nullptr;