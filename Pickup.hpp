#ifndef Pickup_HPP
#define Pickup_HPP

#include "Collider.hpp"
#include "pickupTypes.h"

class Pickup: public Collider{
public:
	virtual bool use() { return pickupUsable; }
	float getPickupDistance() { return pickupDistance; }
	pickupTypes getPickupType() { return type; }
protected:
	float pickupDistance = 0;
	pickupTypes type = pickupTypes::none;
	bool pickupUsable = true;
};

#endif //Pickup_HPP