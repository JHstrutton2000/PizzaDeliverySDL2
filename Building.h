#include "SDL.h"
#include "Rendered.hpp"
#include "Controllable.hpp"
#include "Scene.h"
#include "Door.h"

class Building : public Rendered, public Controllable{ // : public Destructible {
public:
	Building(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x7F, 0x7F, 0x7F, 0xFF });
	~Building();

	void Render(SDL_Renderer* renderer, float* offset, int drawStage);

	void interact(Controllable* object) override;
	bool interactable() override;
	float* getPosition() override;
	float* getCenter() override;
	Door* getDoor();
	void setOutDoor(Door* outDoor);
private:
	SDL_FRect* doorPos;
	//SDL_FRect* yardPos;
	Scene* scene;
	Door* door;
};