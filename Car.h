#include <SDL.h>
#include "Rendered.hpp"
#include "Controllable.hpp"
#include <string>

class Car : public Rendered, public Controllable{
public:
	Car(SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x20, 0x20, 0x20, 0x00 });
	~Car();

	void Render(SDL_Renderer* renderer);
	void applyPosition(float* move) override;
	float* getPosition() override;

	void interact(Controllable* object) override;
	bool interactable() override;
	bool canInteract() override;
private:
	SDL_FPoint topRight;
	SDL_FPoint topLeft;
	SDL_FPoint bottomRight;
	SDL_FPoint bottomLeft;

	Controllable* driver;
};