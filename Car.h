#include <SDL.h>
#include "RenderObject.h"
#include "Physics.hpp"
#include <string>

class Car : public RenderObj, public Physics{
public:
	Car(SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x20, 0x20, 0x20, 0x00 });
	~Car();

	void Render(SDL_Renderer* renderer);
	void applyPosition(float* move) override;
	float* getPosition() override;

	void interact(Physics* object) override;
	bool interactable() override;
	bool canInteract() override;
private:
	SDL_FPoint topRight;
	SDL_FPoint topLeft;
	SDL_FPoint bottomRight;
	SDL_FPoint bottomLeft;

	Physics* driver;
};