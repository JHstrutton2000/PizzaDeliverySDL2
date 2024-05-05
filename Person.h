#include <SDL.h>
#include "Controllable.hpp"
#include "Rendered.hpp"
#include "Inventory.hpp"
#include "Quest.hpp"
#include "Scene.h"

class Person : public Rendered, public Controllable, public Inventory{
public:
	Person(Scene* _scene, SDL_FRect* _pos, SDL_Color* _color = new SDL_Color{ 0x20, 0x90, 0x20, 0x00 });
	~Person();

	void setScene(Scene* _scene) {
		scene->renderManager->removeObject(this);
		scene->physicsManager->removeObject(this);
		scene->interactableManager->removeObject(this);
		scene->collisionManager->removeObject(this);

		scene = _scene;

		scene->renderManager->addObject(this);
		scene->physicsManager->addObject(this);
		scene->interactableManager->addObject(this);
		scene->collisionManager->addObject(this);
	}

	void Render(SDL_Renderer* renderer, float* offset, int drawStage) override;
	void RenderUI(SDL_Renderer* renderer, float* offset) override;

	void applyPosition(float* move) override;
	void interact(Controllable* object) override;
	float* getPosition() override;
	float* getCenter() override;
	bool canInteract() override;

	void onCollide(Collider* object) override;
private:
	Scene* scene;
};