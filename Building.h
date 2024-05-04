#include "SDL.h"
#include "Rendered.hpp"
#include "Controllable.hpp"
#include "Scene.h"

class Building : public Rendered, public Controllable{ // : public Destructible {
public:
	Building(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x7F, 0x7F, 0x7F, 0xFF });
	~Building();

	void Render(SDL_Renderer* renderer, int stage);

	void interact(Controllable* object) override;
	bool interactable() override;
	float* getPosition() override;
	float* getCenter() override;
private:
	SDL_FRect* doorPos;
	Scene* scene;
	//SDL_FRect* yardPos;
};