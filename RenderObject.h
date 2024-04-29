#pragma once

#include <SDL.h>
#include <vector>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

#define SetRenderColor(renderer, color) do{ SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a); } while(0)
#define DrawLine(renderer, p1, p2) do { SDL_RenderDrawLineF(renderer, p1.x, p1.y, p2.x, p2.y); } while(0)

class RenderObj {
protected:
	void* pos;
	float* rot;
	SDL_Color* color;
	SDL_Renderer* renderer;
public:
	virtual void Render(SDL_Renderer* renderer) { return; }
};

class RenderManager {
public:
	RenderManager();
	~RenderManager();

	void render();
	void addObject(RenderObj* object);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<RenderObj*> objects;
};

extern RenderManager* renderManager;