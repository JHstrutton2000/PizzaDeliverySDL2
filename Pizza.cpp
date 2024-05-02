#include "Pizza.h"
#include "renderManager.h"

Pizza::Pizza(SDL_FRect* _pos, SDL_Color* _color) {
	pos = (void*)_pos;
	color = _color;

	_pos->w = 10;
	_pos->h = 10;

	maxAcceleration = 0.1f;
	maxVelocity = 0.1f;

	stage = 1;

	pickupDistance = 5;

	renderManager->addObject(this);
}

Pizza::~Pizza() {

}

void Pizza::Render(SDL_Renderer* renderer, int stage) {
	if (disabled) {
		return;
	}

	SetRenderColor(renderer, color);

	SDL_RenderFillRectF(renderer, (SDL_FRect*)pos);
}

float* Pizza::getPosition() {
	return (float*)pos;
}