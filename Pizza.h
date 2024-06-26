#include <SDL.h>
#include "Controllable.hpp"
#include "Rendered.hpp"
#include "Pickup.hpp"
#include "Scene.h"

class Pizza : public Rendered, public Pickup {
public:
	Pizza(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0xFF, 0x7F, 0x50, 0x00 });
	~Pizza();

	void Render(SDL_Renderer* renderer, float* offset, int drawStage) override;
	float* getPosition() override;
	bool use() override;
private:
	Scene* scene;
};