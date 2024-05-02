#include "SDL.h"
#include "Rendered.hpp"
#include "Controllable.hpp"

class Building : public Rendered, public Controllable { // : public Destructible {
public:
	Building(SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x7F, 0x7F, 0x7F, 0xFF });
	~Building();

	void Render(SDL_Renderer* renderer, int stage);

	void interact(Controllable* object) override;
	bool interactable() override;

private:
	SDL_FRect* doorPos;
	//SDL_FRect* yardPos;
};