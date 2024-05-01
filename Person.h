#include <SDL.h>
#include "Controllable.hpp"
#include "Rendered.hpp"

class Person : public Rendered, public Controllable{
public:
	Person(SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x20, 0x90, 0x20, 0x00 });
	~Person();

	void Render(SDL_Renderer* renderer);
	void applyPosition(float* move) override;
	void interact(Controllable* object) override;
	float* getPosition() override;
	bool canInteract() override;
};