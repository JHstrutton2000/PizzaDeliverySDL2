#ifndef Collider_HPP
#define Collider_HPP

#include "Physics.hpp"

class Collider: public Physics {
public:
	bool colliding(Collider* object) {
		if (disabled || object->disabled) {
			return false;
		}

		for (int i = 0; i < colliderBlackList.size(); i++) {
			if (object == colliderBlackList[i]) {
				return false;
			}
		}

		float dist = object->distanceFromCenter(getCenter());
		float minRadius = (object->getCollisionRadius() + collisionRadius) / 2;

		if (dist <= minRadius) {
			if (object->runsCollide()) {
				onCollide(object);
			}

			return true;
		}

		return false;
	}

	void addCollisionBlackList(Collider* collider) {
		colliderBlackList.push_back(collider);
	}

	static void setCollisionBlackLists(Collider* collider1, Collider* collider2) {
		collider1->addCollisionBlackList(collider2);
		collider2->addCollisionBlackList(collider1);
	}

	float getCollisionRadius() {
		return collisionRadius;
	}

	virtual bool runsCollide() {
		return collideable;
	}

	virtual void onCollide(Collider* object) {
		//reflect(1);
		return;
	}

	void reflect(int scaler) {
		Acceleration[0] *= -1;
		Acceleration[1] *= -1;

		Velocity[0] *= -scaler * collisionRadius;// -(2 * Velocity[0] + 2);
		Velocity[1] *= -scaler * collisionRadius;// -(2 * Velocity[1] + 2);
	}
protected:
	float collisionRadius = 0;
	bool collideable = false; 
	std::vector<Collider*> colliderBlackList;
};

#endif //Collider_HPP