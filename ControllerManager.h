#include <SDL.h>
#include "Controllable.hpp"

class ControllerManager {
public:
	void AssignControlledObject(Controllable* setObject);
	void keyDown(SDL_KeyboardEvent* key);
	void keyUp(SDL_KeyboardEvent* key);

	void update();

private:
	Controllable* object;
	bool w_down = false;
	bool s_down = false;
	bool a_down = false;
	bool d_down = false;
	bool e_down = false;
};

extern ControllerManager* controllerManager;