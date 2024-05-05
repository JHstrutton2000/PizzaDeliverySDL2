#include "Scene.h"

Scene::Scene(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Color* _color) {
	renderManager = new RenderManager(_window, _renderer, _color);
	interactableManager = new InteractableManager();
	collisionManager = new CollisionManager();
	physicsManager = new PhysicsManager();
	questManager = new QuestManager();

	posOffset = new float[2] {0, 0};
}

void Scene::update() {
	if (followPos) {
		float screenMaxXBound = 0.90 * SCREEN_WIDTH;
		float screenMinXBound = 0.10 * SCREEN_WIDTH;

		float screenMaxYBound = 0.90 * SCREEN_HEIGHT;
		float screenMinYBound = 0.10 * SCREEN_HEIGHT;

		if (followPos[0] >= posOffset[0] + screenMaxXBound) {
			posOffset[0] = followPos[0] - screenMaxXBound;
		}
		else if (followPos[0] <= posOffset[0] + screenMinXBound) {
			posOffset[0] = followPos[0] - screenMinXBound;
		}

		if (followPos[1] >= posOffset[1] + screenMaxYBound) {
			posOffset[1] = followPos[1] - screenMaxYBound;
		}
		else if (followPos[1] <= posOffset[1] + screenMinYBound) {
			posOffset[1] = followPos[1] - screenMinYBound;
		}
	}

	physicsManager->update();
	collisionManager->update();
}

void Scene::render() {
	renderManager->render(posOffset);
}

void Scene::setFollowPos(float* pos) {
	followPos = pos;
}

float* Scene::getOffset()
{
	return posOffset;
}
