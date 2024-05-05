#include "Person.h"

#include "RenderManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"
#include "CollisionManager.h"

Person::Person(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color) {
	pos = (void*)_pos;
	color = _color;

	_pos->w = 10;
	_pos->h = 20;

	maxAcceleration = 0.1f;
	maxVelocity = 0.1f;

	stage = 1;

	scene = _scene;

	scene->renderManager->addObject(this);
	scene->physicsManager->addObject(this);
	scene->interactableManager->addObject(this);
	scene->collisionManager->addObject(this);

	collisionRadius = (_pos->h);
	collideable = true;
}

Person::~Person() {
	scene->renderManager->removeObject(this);
	scene->physicsManager->removeObject(this);
	scene->interactableManager->removeObject(this);
	scene->collisionManager->removeObject(this);
}

void Person::Render(SDL_Renderer* renderer, float* offset, int drawStage) {
	if (disabled) {
		return;
	}

	if (stage == drawStage) {

		SDL_FRect* tempPos = (SDL_FRect*)pos;
		SDL_FRect* adjustedPos = new SDL_FRect{ tempPos->x  - offset[0], tempPos->y  -  offset[1], tempPos->w, tempPos->h };

		SetRenderColor(renderer, color);
		SDL_RenderFillRectF(renderer, adjustedPos);
	}
} 

void Person::RenderUI(SDL_Renderer* renderer, float* offset) {

	renderQuests(renderer, offset);

	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	//SDL_RenderDrawRectF(renderer, new SDL_FRect{
	//	tempPos->x - 40, 
	//	tempPos->y - 20,
	//	40,
	//	20
	//});
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

float* Person::getCenter() {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	return new float[2] {tempPos->x + tempPos->w / 2, tempPos->y + tempPos->h / 2};
}

bool Person::canInteract() {
	//exit to person.
	return true;
}

void Person::onCollide(Collider* object) {
	Pickup* item = dynamic_cast<Pickup*>(object);

	if (item) {
		pickup(item);
	}
	else {
		reflect(2);
	}
}