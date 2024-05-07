#include "Door.h"
#include "SceneManager.h"
#include "Person.h"

Door::Door(Scene* _curScene, SDL_FRect* _pos) {
	if (_pos->w <= 0 || _pos->h <= 0) {
		_pos->w = 5;
		_pos->h = 5;
	}

	curScene = _curScene;
	pos = (void*)_pos;
	renderPos = new SDL_FRect{ 0, 0, _pos->w, _pos->h };
	Center = new float[2];

	collideable = true;

	curScene->renderManager->addObject(this);
	curScene->collisionManager->addObject(this);

	collisionRadius = _pos->w;

	stage = 4;
}

Door::~Door() {

}

void Door::Render(SDL_Renderer* renderer, float* offset, int drawStage){
	if (stage == drawStage) {
		SDL_FRect* tempPos = (SDL_FRect*)pos;
		SDL_FRect* rendPos = (SDL_FRect*)renderPos;

		rendPos->x = tempPos->x - offset[0];
		rendPos->y = tempPos->y - offset[1];

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRectF(renderer, rendPos);
	}
}

float* Door::getPosition()
{
	return (float*)pos;
}

float* Door::getCenter() {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	Center[0] = tempPos->x + tempPos->w / 2;
	Center[1] = tempPos->y + tempPos->h / 2;

	return Center;
}

void Door::onCollide(Collider* object) {
	Person* person = dynamic_cast<Person*>(object);

	if (person && outDoor) {
		Scene* outScene = outDoor->getScene();

		sceneManager->setActiveScene(outScene);
		person->setScene(outScene);

		float* personPos = person->getCenter();
		float* tempPos = getCenter();
		float* outDoorPos = outDoor->getCenter();

		float xoff = personPos[0] - tempPos[0];
		float yoff = personPos[1] - tempPos[1];

		personPos = person->getPosition();

		personPos[0] = outDoorPos[0] - 2*xoff;
		personPos[1] = outDoorPos[1] - 2*yoff;
	}
}

void Door::setOutDoor(Door* door){
	outDoor = door;
}

Scene* Door::getScene()
{
	return curScene;
}

void Door::setDestinations(Door* door1, Door* door2) {
	door1->setOutDoor(door2);
	door2->setOutDoor(door1);
}
