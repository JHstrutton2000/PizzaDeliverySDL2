#include "vector"
#include "Physics.hpp"

class InteractableManager {
public:
	void addObject(Physics* object);
	Physics* nearestInteractable(Physics* object);
private:
	std::vector<Physics*> objects;
};

extern InteractableManager* interactableManager;