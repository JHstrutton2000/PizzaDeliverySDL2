#ifndef Controllable_HPP
#define Controllable_HPP

#include "Physics.hpp"

class Controllable: public Physics {
public:
	virtual bool interactable() { return false; }
	virtual bool canInteract() { return false; }
	virtual void interact(Controllable* object) { return; }
};

#endif //Controllable_HPP