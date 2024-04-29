#include <SDL.h>
#include "Physics.hpp"
#include "RenderObject.h"

class Person : public RenderObj, public Physics {
public:
	Person(SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x20, 0x90, 0x20, 0x00 });
	~Person();

	void Render(SDL_Renderer* renderer);
	void applyPosition(float* move) override;
	void interact(Physics* object) override;
	float* getPosition() override;
	bool canInteract() override;
};