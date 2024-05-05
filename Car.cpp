#include "Car.h"
#include "ControllerManager.h"

#include "sceneManager.h"
#include "RenderManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"
#include "CollisionManager.h"

Car::Car(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color){
	_pos->w = 20;
	_pos->h = 40;

	pos = (void*)_pos;
	renderPos = new SDL_FRect{ 0, 0, _pos->w, _pos->h };
	rot = 45.0f;
	color = _color;

	maxAcceleration = 0.5;
	maxVelocity = 1;

	stage = 2;
	scene = _scene;

	scene->renderManager->addObject(this);
	scene->physicsManager->addObject(this);
	scene->collisionManager->addObject(this);
	scene->interactableManager->addObject(this);

	collisionRadius = (_pos->h);
	collideable = true;
}

Car::~Car() {
	scene->renderManager->removeObject(this);
	scene->physicsManager->removeObject(this);
	scene->collisionManager->removeObject(this);
	scene->interactableManager->removeObject(this);
}

void Car::Render(SDL_Renderer* renderer, float* offset, int drawStage) {
	if (color == nullptr) {
		return;
	}


	if (stage == drawStage) {
		SetRenderColor(renderer, color);

		SDL_FRect* tempPos = (SDL_FRect*)pos;

		//SDL_FRect* adjustedPos = new SDL_FRect{ tempPos->x - offset[0], tempPos->y - offset[1], tempPos->w, tempPos->h};
		SDL_FRect* adjustedPos = (SDL_FRect*)renderPos;
		adjustedPos->x = tempPos->x - offset[0];
		adjustedPos->y = tempPos->y - offset[1];


		float w = tempPos->w / 2;
		float h = tempPos->h / 2;

		topLeft     = { adjustedPos->x - w, adjustedPos->y - h }; // top left
		bottomLeft  = { adjustedPos->x - w, adjustedPos->y + h }; // bottom left
		topRight    = { adjustedPos->x + w, adjustedPos->y - h }; // top right
		bottomRight = { adjustedPos->x + w, adjustedPos->y + h }; // buttom right

		float dist = sqrtf(pow(w / 2, 2) + pow(h / 2, 2));

		//printf("velocity x: %.6f y: %.6f \n", Velocity[0], Velocity[1]);

		SDL_FPoint adjustedtopRight = { w / 2,  h / 2 };
		SDL_FPoint adjustedtopLeft = { -w / 2,  h / 2 };
		SDL_FPoint adjustedbottomRight = { w / 2, -h / 2 };
		SDL_FPoint adjustedbottomLeft = { -w / 2, -h / 2 };

		float angleTopRight = atanf(adjustedtopRight.y / adjustedtopRight.x) - heading;
		float angleTopLeft = atanf(adjustedtopLeft.y / adjustedtopLeft.x) - heading;
		float angleBottomRight = atanf(adjustedbottomRight.y / adjustedbottomRight.x) - heading;
		float angleBottomLeft = atanf(adjustedbottomLeft.y / adjustedbottomLeft.x) - heading;

		adjustedtopRight = {
			sinf(angleTopRight) * dist + adjustedPos->x,
			cosf(angleTopRight) * dist + adjustedPos->y
		};

		adjustedtopLeft = {
			sinf(angleTopLeft) * dist + adjustedPos->x,
			cosf(angleTopLeft) * dist + adjustedPos->y
		};

		adjustedbottomRight = {
			sinf(angleBottomRight) * -dist + adjustedPos->x,
			cosf(angleBottomRight) * -dist + adjustedPos->y
		};

		adjustedbottomLeft = {
			sinf(angleBottomLeft) * -dist + adjustedPos->x,
			cosf(angleBottomLeft) * -dist + adjustedPos->y
		};


		DrawLine(renderer, adjustedtopLeft, adjustedbottomLeft);
		DrawLine(renderer, adjustedtopRight, adjustedbottomRight);
		DrawLine(renderer, adjustedtopLeft, adjustedtopRight);
		DrawLine(renderer, adjustedbottomLeft, adjustedbottomRight);
	}
	
}

void Car::applyPosition(float* move) {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	tempPos->x += move[0];
	tempPos->y += move[1];
}

float* Car::getPosition() {
	return (float*)pos;
}

//Something wants to interact with me.
void Car::interact(Controllable* object) {
	controllerManager->AssignObject(this);
	driver = object;
	driver->disabled = true;

	sceneManager->getActiveScene()->setFollowPos(getPosition());
}

bool Car::interactable() {
	return true; 
}

bool Car::canInteract() { 
	controllerManager->AssignObject(driver);
	
	driver->setPosition(getPosition());
	driver->disabled = false;

	sceneManager->getActiveScene()->setFollowPos(driver->getPosition());

	driver = nullptr;

	return false; 
}

void Car::onCollide(Collider* object) {
	reflect(1);
}