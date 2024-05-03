#ifndef Pickup_HPP
#define Pickup_HPP

#include "Collider.hpp"

class Pickup: public Collider {
public:
	virtual bool use() { return false; }
	float getPickupDistance() { return pickupDistance; }
protected:
	float pickupDistance = 0;
};

#endif //Pickup_HPP