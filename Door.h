#ifndef Door_H
#define Door_H

#include "Scene.h"

class Door: public Rendered, public Controllable {
public:
	Door(Scene* _curScene, Scene* _destScene, SDL_FRect* _pos);
	~Door();
	void Render(SDL_Renderer* renderer, int stage);

	float* getPosition() override;
	float* getCenter() override;

	void onCollide(Collider* object) override;

	void setOutDoor(Door* door);
private:
	Scene* curScene;
	Scene* destScene;

	Door* outDoor;
};

#endif //Door_H