#include "ControllerManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"
#include "CollisionManager.h"
#include "Person.h"

void ControllerManager::AssignObject(Controllable* setObject) {
	object = setObject;
}

void ControllerManager::update() {
	if (w_down) {
		object->applyAcceleration(new float[2] {0, -1});
	}
	else if (s_down) {
		object->applyAcceleration(new float[2] {0, 1});
	}

	if (a_down) {
		object->applyAcceleration(new float[2] {-1, 0});
	}
	else if (d_down) {
		object->applyAcceleration(new float[2] {1, 0});
	}
}

void ControllerManager::keyUp(SDL_KeyboardEvent* key) {
	switch (key->keysym.sym) {
		case SDLK_w:
			w_down = false;
			break;
		case SDLK_s:
			s_down = false;
			break;
		case SDLK_a:
			a_down = false;
			break;
		case SDLK_d:
			d_down = false;
			break;
		case SDLK_e:
			e_down = false;
			break;
	}
}

void ControllerManager::keyDown(SDL_KeyboardEvent* key) {
	switch (key->keysym.sym) {
		case SDLK_w:
			w_down = true;
			break;
		case SDLK_s:
			s_down = true;
			break;
		case SDLK_a:
			a_down = true;
			break;
		case SDLK_d:
			d_down = true;
			break;
		case SDLK_e:
			if (!e_down) {
				if (!object->canInteract()) {
					break;
				}

				Controllable* nearestInteractable = interactableManager->nearestInteractable(object);

				if (nearestInteractable) {
					nearestInteractable->interact(object);
				}
				else {
					Person* person = dynamic_cast<Person*>(object);

					if (person) {
						person->useItemType(pickupTypes::weapon);
					}
				}
			}

			e_down = true;
			break;
	}
}

ControllerManager* controllerManager = nullptr;