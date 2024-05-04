#include "RenderManager.h"

RenderManager::RenderManager() {
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
		return;
	}
}

RenderManager::~RenderManager() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderManager::render() {
	if (renderer == nullptr) {
		return;
	}

	SDL_SetRenderDrawColor(renderer, 0x00, 0x50, 0x00, 0);
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
	
	SDL_RenderPresent(renderer);
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

RenderManager* renderManager = nullptr;