#ifndef Controllable_HPP
#define Controllable_HPP

#include "Collider.hpp"

class Controllable: public Collider {
public:
	virtual bool interactable() { return false; }
	virtual bool canInteract() { return false; }
	virtual void interact(Controllable* object) { return; }
};

#endif //Controllable_HPP