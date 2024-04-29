#include "Car.h"
#include "ControllerManager.h"

Car::Car(SDL_FRect* _pos, SDL_Color* _color){
	_pos->w = 20;
	_pos->h = 40;

	pos = (void*)_pos;
	rot = new float(45.0f);
	color = _color;

	maxAcceleration = 2;
	maxVelocity = 2;
}

Car::~Car() {
	delete pos;
	delete color;
}

void Car::Render(SDL_Renderer* renderer) {
	if (color == nullptr) {
		return;
	}

	SetRenderColor(renderer, color);

	SDL_FRect* tempPos = (SDL_FRect*)pos;

	float w = tempPos->w / 2;
	float h = tempPos->h / 2;

	topLeft     = { tempPos->x - w, tempPos->y - h }; // top left
	bottomLeft  = { tempPos->x - w, tempPos->y + h }; // bottom left
	topRight    = { tempPos->x + w, tempPos->y - h }; // top right
	bottomRight = { tempPos->x + w, tempPos->y + h }; // buttom right

	float dist = sqrtf(pow(w/2, 2) + pow(h/2, 2));

	//printf("velocity x: %.6f y: %.6f \n", Velocity[0], Velocity[1]);

	SDL_FPoint adjustedtopRight    = {  w/2,  h/2 };
	SDL_FPoint adjustedtopLeft     = { -w/2,  h/2 };
	SDL_FPoint adjustedbottomRight = {  w/2, -h/2 };
	SDL_FPoint adjustedbottomLeft  = { -w/2, -h/2 };
	
	float angleTopRight    = atanf(adjustedtopRight.y    / adjustedtopRight.x   ) - heading;
	float angleTopLeft	   = atanf(adjustedtopLeft.y     / adjustedtopLeft.x    ) - heading;
	float angleBottomRight = atanf(adjustedbottomRight.y / adjustedbottomRight.x) - heading;
	float angleBottomLeft  = atanf(adjustedbottomLeft.y  / adjustedbottomLeft.x ) - heading;

	adjustedtopRight = { 
		sin(angleTopRight) * dist + tempPos->x, 
		cos(angleTopRight) * dist + tempPos->y 
	};

	adjustedtopLeft = { 
		sin(angleTopLeft) * dist + tempPos->x,
		cos(angleTopLeft) * dist + tempPos->y
	};

	adjustedbottomRight = {
		sin(angleBottomRight) * -dist + tempPos->x,
		cos(angleBottomRight) * -dist + tempPos->y
	};
	
	adjustedbottomLeft = {
		sin(angleBottomLeft) * -dist + tempPos->x,
		cos(angleBottomLeft) * -dist + tempPos->y
	};


	DrawLine(renderer, adjustedtopLeft, adjustedbottomLeft);
	DrawLine(renderer, adjustedtopRight, adjustedbottomRight);
	DrawLine(renderer, adjustedtopLeft, adjustedtopRight);
	DrawLine(renderer, adjustedbottomLeft, adjustedbottomRight);

	
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
void Car::interact(Physics* object) {
	controllerManager->AssignControlledObject(this);
	driver = object;
	driver->disabled = true;
}

bool Car::interactable() {
	return true; 
}

bool Car::canInteract() { 
	controllerManager->AssignControlledObject(driver);
	
	driver->setPosition(getPosition());
	driver->disabled = false;

	driver = nullptr;

	return false; 
}