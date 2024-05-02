#include "Person.h"

#include "RenderManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"

Person::Person(SDL_FRect* _pos, SDL_Color* _color) {
	pos = (void*)_pos;
	color = _color;

	_pos->w = 10;
	_pos->h = 20;

	maxAcceleration = 0.1f;
	maxVelocity = 0.1f;

	stage = 1;

	renderManager->addObject(this);
	physicsManager->addObject(this);
	interactableManager->addObject(this);
}

Person::~Person() {

}

void Person::Render(SDL_Renderer* renderer, int stage) {
	if (disabled) {
		return;
	}

	if (this->stage == stage) {
		SetRenderColor(renderer, color);

		SDL_RenderFillRectF(renderer, (SDL_FRect*)pos);
	}
} 

void Person::RenderUI(SDL_Renderer* renderer, int stage) {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	SDL_RenderDrawRectF(renderer, new SDL_FRect{
		tempPos->x - 40, 
		tempPos->y - 20,
		40,
		20
	});
}

void Person::applyPosition(float* move) {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	tempPos->x += move[0];
	tempPos->y += move[1];
}

//something wants to interact with you.
void Person::interact(Controllable* object) {
	return;
}

float* Person::getPosition() {
	return (float*)pos;
}

bool Person::canInteract() {
	//exit to person.
	return true;
}