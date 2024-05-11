#ifndef Door_H
#define Door_H

#include "Scene.h"

class Door: public Rendered, public Controllable {
public:
	Door(Scene* _curScene, SDL_FRect* _pos);
	~Door();
	void Render(SDL_Renderer* renderer, float* offset, int drawStage);

	float* getPosition() override;
	float* getCenter() override;

	void onCollide(Collider* object) override;

	void setOutDoor(Door* door);
	Door* getOutDoor();
	Scene* getScene();
	static void setDestinations(Door* door1, Door* door2);
private:
	Scene* curScene;
	//Scene* destScene;

	Door* outDoor;
};

#endif //Door_H