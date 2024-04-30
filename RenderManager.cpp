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

	SDL_SetRenderDrawColor(renderer, 0, 250, 0, 0);
	SDL_RenderClear(renderer);

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Render(renderer);
	}

	SDL_RenderPresent(renderer);
}

void RenderManager::addObject(Rendered* object) {
	objects.push_back(object);
}

RenderManager* renderManager = nullptr;