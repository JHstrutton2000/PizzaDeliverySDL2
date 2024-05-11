#include "SDL.h"

#include "Rendered.hpp"
#include "Physics.hpp"
#include "Dialog.hpp"

#include "Scene.h"

#include <string>

class Sign: public Rendered, public Controllable, public Dialog {
public:
	Sign(Scene* _scene, SDL_FRect* _pos, std::string text, SDL_Color* _color = new SDL_Color{ 0x8B, 0x45, 0x13, 0x00 });

	void Render(SDL_Renderer* renderer, float* offset, int drawStage) override;
	void RenderUI(SDL_Renderer* renderer, float* offset) override;
	float* getPosition() override;
	float* getCenter() override;
	void interact(Controllable* object) override;
	bool interactable() override;
	bool canInteract() override;
protected:
	Scene* scene;

private:
	SDL_FRect* dialogPos;
};