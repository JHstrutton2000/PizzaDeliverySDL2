#include <SDL.h>
#include "Controllable.hpp"
#include "Rendered.hpp"
#include "Pickup.hpp"

class Pizza : public Rendered, public Pickup {
public:
	Pizza(SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x00, 0x00, 0xFF, 0x00 });
	~Pizza();

	void Render(SDL_Renderer* renderer);
	float* getPosition();
};