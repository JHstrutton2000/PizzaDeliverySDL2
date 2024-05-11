#include "Sign.h"

Sign::Sign(Scene* _scene, SDL_FRect* _pos, std::string text, SDL_Color* _color) {
	if (_pos->w <= 0 || _pos->h <= 0) {
		_pos->w = 10;
		_pos->h = 10;
	}

	color = _color;
	pos = (void*)_pos;
	Center = new float[2];
	renderPos = new SDL_FRect{
		0, 
		0, 
		_pos->w, 
		_pos->h 
	};

	dialogPos = new SDL_FRect{
		0,
		SCREEN_HEIGHT - 100,
		SCREEN_WIDTH,
		200
	};

	addDialog(text);

	scene = _scene;

	stage = 3;
	interactRadius = 2;

	scene->renderManager->addObject(this);
	scene->renderManager->addUIObject(this);
	scene->interactableManager->addObject(this);
}

void Sign::Render(SDL_Renderer* renderer, float* offset, int drawStage) {
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

void Sign::RenderUI(SDL_Renderer* renderer, float* offset) {

	if (lastInteract && dialogOpen) {
		if (!withinRadius(lastInteract->getCenter(), 50)) {
			closeDialog();
		}

		SDL_SetRenderDrawColor(renderer, 0x50, 0x50, 0x50, 0x00);

		SDL_RenderFillRectF(renderer, dialogPos);

		//Draw Text
		//readDialog().c_str();
	}
}

float* Sign::getPosition() {
	return (float*)pos;
}

float* Sign::getCenter() {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	Center[0] = tempPos->x + tempPos->w / 2;
	Center[1] = tempPos->y + tempPos->h / 2;

	return Center;
}


//Something wants to interact with me.
void Sign::interact(Controllable* object) {
	lastInteract = object;
	nextDialog();
}

bool Sign::interactable() {
	return true;
}

bool Sign::canInteract() {

	return false;
}
