#ifndef Inventory_HPP
#define Inventory_HPP

#include <vector>
#include "Pickup.hpp"
#include "pickupTypes.hpp"

class Inventory {
public:
	void pickup(Pickup* item) {
		addItem(item);
		item->disabled = true;
	}

	void useItem(int itemIndex) {
		if (itemIndex >= items.size()) {
			return;
		}

		if (items[itemIndex]->use()) {
			removeItem(itemIndex);
		}
	}
	
	bool useItemType(pickupTypes type) {
		for (int i = 0; i < items.size(); i++) {
			if (items[i]->getPickupType() == type && items[i]->use()) {
				removeItem(i);

				return true;
			}
		}

		return false;
	}

	void dropItem(int itemIndex) {
		if (itemIndex >= items.size()) {
			return;
		}

		removeItem(itemIndex);
	}
protected:
	int inventorySize = 5;

private:
	std::vector<Pickup*> items;

	void removeItem(int itemIndex) {
		//Pickup* pickup = items[itemIndex];

		//delete pickup;

		items.erase(items.begin() + itemIndex);
	}

	void addItem(Pickup* item) {
		items.push_back(item);
	}
};

#endif //Inventory_HPP