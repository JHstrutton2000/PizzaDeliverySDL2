#include "Building.h"

#include "RenderManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"
#include "CollisionManager.h"

#include "Person.h"
#include "pickupTypes.h"

Building::Building(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color) {
	_pos->w = 100;
	_pos->h = 100;

	pos = (void*)_pos;
	renderPos = new SDL_FRect{ 0, 0, _pos->w, _pos->h };
	Center = new float[2];

	rot = 45.0f;
	color = _color;
	scene = _scene;


	//doorPos = new SDL_FRect{ _pos->x + 30, _pos->y + 70, 40, 30 };
	//yardPos = new SDL_FRect{ _pos->x - 10, _pos->y -10, 120, 120 };


	stage = 3;

	scene->interactableManager->addObject(this);
	scene->collisionManager->addObject(this);
	scene->renderManager->addObject(this);

	collisionRadius = (_pos->h);
	interactRadius = collisionRadius/2 + 20;
	collideable = true;
}
Building::~Building() {

	scene->interactableManager->removeObject(this);
	scene->collisionManager->removeObject(this);
	scene->renderManager->removeObject(this);

	//delete yardPos;
	delete doorPos;
}


void Building::Render(SDL_Renderer* renderer, float* offset, int drawStage) {
	if (color == nullptr) {
		return;
	}

	// SDL_SetRenderDrawColor(renderer, 0, 200, 0, 0);
	// SDL_RenderFillRectF(renderer, yardPos);
	if (stage == drawStage) {
		SDL_FRect* tempPos = (SDL_FRect*)pos;
		SDL_FRect* rendPos = (SDL_FRect*)renderPos;

		rendPos->x = tempPos->x - offset[0];
		rendPos->y = tempPos->y - offset[1];

		SetRenderColor(renderer, color);
		SDL_RenderFillRectF(renderer, rendPos);
	}
}

void Building::interact(Controllable* object) {
	Person* person = dynamic_cast<Person*>(object);

	if (person) {
		if (person->useItemType(pickupTypes::pizza)) {
		}
	}
}

bool Building::interactable() {
	return true;
}

float* Building::getPosition() {
	return (float*)pos;
}

float* Building::getCenter() {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	Center[0] = tempPos->x + tempPos->w / 2;
	Center[1] = tempPos->y + tempPos->h / 2;

	return Center;
}