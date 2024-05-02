#ifndef Pickup_HPP
#define Pickup_HPP

#include "Physics.hpp"

class Pickup: public Physics {
public:
	virtual bool use() { return false; }
	float getPickupDistance() { return pickupDistance; }
protected:
	float pickupDistance = 0;
};

#endif //Pickup_HPP