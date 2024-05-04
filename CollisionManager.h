#ifndef CollisionManager_h
#define CollisionManager_h

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

#endif //CollisionManager_h