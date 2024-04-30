#pragma once

#include <SDL.h>
#include <vector>
#include <iostream>
#include "Rendered.hpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class RenderManager {
public:
	RenderManager();
	~RenderManager();

	void render();
	void addObject(Rendered* object);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<Rendered*> objects;
};

extern RenderManager* renderManager;