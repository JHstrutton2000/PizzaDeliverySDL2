#ifndef Inventory_HPP
#define Inventory_HPP

#include <vector>
#include "Pickup.hpp"
#include "Quest.hpp"

#include "pickupTypes.h"
#include "questTypes.h"

class Inventory: public Quest {
public:
	void pickup(Pickup* item) {
		addItem(item);
		item->disabled = true;

		updateQuest(item, questTypes::deliver);
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

	void useItem(int itemIndex) {
		if (itemIndex >= items.size()) {
			return;
		}

		if (items[itemIndex]->use()) {

			removeItem(itemIndex);
		}
	}

	void removeItem(int itemIndex) {
		//Pickup* pickup = items[itemIndex];

		//delete pickup;

		removeQuest(items[itemIndex]);
		items.erase(items.begin() + itemIndex);
	}

	void addItem(Pickup* item) {
		items.push_back(item);
	}
};

#endif //Inventory_HPP