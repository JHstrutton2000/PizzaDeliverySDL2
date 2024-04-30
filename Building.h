#include "SDL.h"
#include "RenderObject.h"
#include "Physics.hpp"

class Building : public RenderObj, public Physics { // : public Destructible {
public:
	Building(SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x7F, 0x7F, 0x7F, 0xFF });
	~Building();

	void Render(SDL_Renderer* renderer);

	void interact(Physics* object) override;
	bool interactable() override;
};