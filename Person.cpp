#include "Person.h"

Person::Person(SDL_FRect* _pos, SDL_Color* _color) {
	pos = (void*)_pos;
	color = _color;

	_pos->w = 10;
	_pos->h = 20;

	maxAcceleration = 0.1f;
	maxVelocity = 0.1f;

	stage = 1;
}

Person::~Person() {

}

void Person::Render(SDL_Renderer* renderer) {
	if (disabled) {
		return;
	}

	SetRenderColor(renderer, color);

	SDL_RenderFillRectF(renderer, (SDL_FRect*)pos);
}

void Person::applyPosition(float* move) {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	tempPos->x += move[0];
	tempPos->y += move[1];
}

//something wants to interact with you.
void Person::interact(Controllable* object) {

}

float* Person::getPosition() {
	return (float*)pos;
}

bool Person::canInteract() {
	//exit to person.
	return true;
}