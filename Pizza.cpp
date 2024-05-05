#include "Pizza.h"
#include "renderManager.h"
#include "collisionManager.h"
#include "QuestManager.h"

#include "pickupTypes.h"

Pizza::Pizza(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color) {
	color = _color;

	_pos->w = 10;
	_pos->h = 10;

	pos = (void*)_pos;
	renderPos = new SDL_FRect{ 0, 0, _pos->w, _pos->h };

	maxAcceleration = 0.1f;
	maxVelocity = 0.1f;

	stage = 1;

	pickupDistance = 5;

	scene = _scene;

	scene->renderManager->addObject(this);
	scene->collisionManager->addObject(this);
	scene->questManager->assignQuest(this);

	collisionRadius = (_pos->h);
	collideable = true;

	type = pickupTypes::pizza;
	pickupUsable = true;
}

Pizza::~Pizza() {
	scene->renderManager->removeObject(this);
	scene->collisionManager->removeObject(this);
}

void Pizza::Render(SDL_Renderer* renderer, float* offset, int drawStage) {
	if (disabled) {
		return;
	}

	if (stage == drawStage) {
		SDL_FRect* tempPos = (SDL_FRect*)pos;
		SDL_FRect* rendPos = (SDL_FRect*)renderPos;

		rendPos->x = tempPos->x - offset[0];
		rendPos->y = tempPos->y - offset[1];

		SetRenderColor(renderer, color);

		SDL_RenderFillRectF(renderer, rendPos);
	}
}

float* Pizza::getPosition() {
	return (float*)pos;
}

bool Pizza::use() {
	disabled = false;

	scene->questManager->assignQuest(this);

	return true; 
}