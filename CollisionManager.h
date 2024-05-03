#include "Collider.hpp"
#include <vector>

class CollisionManager {
public:
	void addObject(Collider* object);
	void removeObject(Collider* object);

	void update();
private:
	std::vector<Collider*> objects;
};

extern CollisionManager* collisionManager;