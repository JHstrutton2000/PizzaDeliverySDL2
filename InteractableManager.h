#include "vector"
#include "Controllable.hpp"

class InteractableManager {
public:
	void addObject(Controllable* object);
	Controllable* nearestInteractable(Controllable* object);
private:
	std::vector<Controllable*> objects;
};

extern InteractableManager* interactableManager;