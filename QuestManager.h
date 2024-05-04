#ifndef QuestManager_HPP
#define QuestManager_HPP

#include <vector>
#include "Quest.hpp"
#include "Pickup.hpp"
#include "Controllable.hpp"

class QuestManager {
public:
	QuestManager();
	void assignObject(Quest* object);
	void assignQuest(Pickup* object);
	void addDestination(Controllable* object);
	Controllable* getSelected();
private:
	std::vector<Controllable*> questDestinations;
	Controllable* selectedDestination;
	Quest* assigned;
};

extern QuestManager* questManager;

#endif //QuestManager_HPP