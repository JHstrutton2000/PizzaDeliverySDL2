#include "Pizza.h"
#include "renderManager.h"
#include "collisionManager.h"
#include "pickup.Types"

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
	collisionManager->addObject(this);

	collisionRadius = (_pos->h);
	collideable = true;

	type = pickupTypes::pizza;
	pickupUsable = true;
}

Pizza::~Pizza() {
	renderManager->removeObject(this);
	collisionManager->removeObject(this);
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