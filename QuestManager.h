#ifndef QuestManager_HPP
#define QuestManager_HPP

#include <vector>
#include "Quest.hpp"
#include "Pickup.hpp"
#include "Controllable.hpp"

class QuestManager {
public:
	void assignObject(Quest* object);
	void assignQuest(Pickup* object);
	void addDestination(Controllable* object);
	Controllable* getSelected();
private:
	std::vector<Controllable*> questDestinations;
	Controllable* selectedDestination;
	Quest* assigned;
};

#endif //QuestManager_HPP