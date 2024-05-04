#include "RenderManager.h"

RenderManager::RenderManager(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Color* _color) {
	window = _window;
	renderer = _renderer;
	backgroundColor = _color;
}

void RenderManager::render() {
	if (renderer == nullptr) {
		return;
	}

	SetRenderColor(renderer, backgroundColor);
	SDL_RenderClear(renderer);

	for (int stage = 0; stage <= maxStage; stage++) {
		for (int i = 0; i < objects.size(); i++) {
			int curStage = objects[i]->getStage();

			if (curStage > maxStage) {
				maxStage = curStage;
			}

			objects[i]->Render(renderer, stage);
		}
	}

	for (int i = 0; i < uiObjects.size(); i++) {
		uiObjects[i]->RenderUI(renderer);
	}
}

void RenderManager::addObject(Rendered* object) {
	objects.push_back(object);
}

void RenderManager::addUIObject(Rendered* object) {
	uiObjects.push_back(object);
}

void RenderManager::removeObject(Rendered* object) {
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

void RenderManager::removeUIObject(Rendered* object) {
	uiObjects.erase(std::remove(uiObjects.begin(), uiObjects.end(), object), uiObjects.end());
}