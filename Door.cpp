#include "Door.h"
#include "SceneManager.h"
#include "Person.h"

Door::Door(Scene* _curScene, Scene* _destScene, SDL_FRect* _pos) {
	_pos->w = 5;
	_pos->h = 5;

	curScene = _curScene;
	destScene = _destScene;
	pos = (void*)_pos;

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
		SDL_FRect* adjustedPos = new SDL_FRect{ tempPos->x  - offset[0], tempPos->y  -  offset[1], tempPos->w, tempPos->h };

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderFillRectF(renderer, adjustedPos);
	}
}

float* Door::getPosition()
{
	return (float*)pos;
}

float* Door::getCenter() {
	SDL_FRect* tempPos = (SDL_FRect*)pos;

	return new float[2] {tempPos->x + tempPos->w / 2, tempPos->y + tempPos->h / 2};
}

void Door::onCollide(Collider* object) {
	Person* person = dynamic_cast<Person*>(object);

	if (person) {
		sceneManager->setActiveScene(destScene);
		person->setScene(destScene);

		float* personPos = person->getCenter();
		float* tempPos = getCenter();
		float* outDoorPos = outDoor->getCenter();

		//float* destPosOffset = destScene->getOffset();
		//float* curSceneOffset = curScene->getOffset();

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
