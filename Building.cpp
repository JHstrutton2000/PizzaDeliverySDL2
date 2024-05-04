#include "Building.h"

#include "RenderManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"
#include "CollisionManager.h"

#include "Person.h"
#include "pickupTypes.hpp"

Building::Building(SDL_FRect* _pos, SDL_Color* _color) {
	_pos->w = 100;
	_pos->h = 100;

	pos = (void*)_pos;
	rot = new float(45.0f);
	color = _color;


	doorPos = new SDL_FRect{ _pos->x + 30, _pos->y + 70, 40, 30 };
	//yardPos = new SDL_FRect{ _pos->x - 10, _pos->y -10, 120, 120 };

	stage = 3;

	interactableManager->addObject(this);
	collisionManager->addObject(this);
	renderManager->addObject(this);

	collisionRadius = (_pos->h);
	interactRadius = collisionRadius/2 + 20;
	collideable = true;
}
Building::~Building() {

	interactableManager->removeObject(this);
	collisionManager->removeObject(this);
	renderManager->removeObject(this);

	//delete yardPos;
	delete doorPos;
}


void Building::Render(SDL_Renderer* renderer, int stage) {
	if (color == nullptr) {
		return;
	}

	// SDL_SetRenderDrawColor(renderer, 0, 200, 0, 0);
	// SDL_RenderFillRectF(renderer, yardPos);

	SetRenderColor(renderer, color);
	SDL_RenderFillRectF(renderer, (SDL_FRect*)pos);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRectF(renderer, doorPos);

}

void Building::interact(Controllable* object) {
	Inventory* inventory = dynamic_cast<Inventory*>(object);

	if (inventory) {
		if (inventory->useItemType(pickupTypes::pizza)) {
			printf("used a pizza!!!");
		}
	}
}

bool Building::interactable() {
	return true;
}

float* Building::getPosition()
{
	return (float*)pos;
}

float* Building::getCenter() {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	return new float[4] {tempPos->x + tempPos->w/2, tempPos->y + tempPos->h/2};
}