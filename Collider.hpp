#ifndef Collider_HPP
#define Collider_HPP

#include "Physics.hpp"

class Collider: public Physics {
public:
	bool colliding(Collider* object) {
		if (object->distance(getPosition()) <= ((object->getCollisionRadius() + collisionRadius) / 2)) {
			if (object->runsCollide()) {
				onCollide(object);
			}

			return true;
		}

		return false;
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
		Velocity[0] *= -scaler * collisionRadius;// -(2 * Velocity[0] + 2);
		Velocity[1] *= -scaler * collisionRadius;// -(2 * Velocity[1] + 2);
	}
protected:
	float collisionRadius = 0;
	bool collideable = false; 
};

#endif //Collider_HPP