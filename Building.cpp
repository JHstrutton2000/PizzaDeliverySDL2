#include "Building.h"

Building::Building(SDL_FRect* _pos, SDL_Color* _color) {
	_pos->w = 100;
	_pos->h = 100;

	pos = (void*)_pos;
	rot = new float(45.0f);
	color = _color;
}
Building::~Building() {

}


void Building::Render(SDL_Renderer* renderer) {
	if (color == nullptr) {
		return;
	}

	SetRenderColor(renderer, color);

	SDL_FRect* tempPos = (SDL_FRect*)pos;
	SDL_FRect* doorPos = new SDL_FRect{ tempPos->x+30, tempPos->y+70, 40, 30};

	SDL_RenderFillRectF(renderer, tempPos);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRectF(renderer, doorPos);
}

void Building::interact(Physics* object) {

}

bool Building::interactable() {
	return true;
}