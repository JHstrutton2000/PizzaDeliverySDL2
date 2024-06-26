#include "QuestManager.h"
#include "Building.h"
#include <ctime> 

void QuestManager::addDestination(Controllable* object){
	questDestinations.push_back(object);
}

void QuestManager::assignObject(Quest* object) {
	assigned = object;
}

void QuestManager::assignQuest(Pickup* object) {
	if (questDestinations.size() <= 0) {
		return;
	}

	srand((unsigned)time(0));

	int randomIndex = rand() % questDestinations.size();

	selectedDestination = questDestinations[randomIndex];

	assigned->addQuest(object, selectedDestination, questTypes::pickup);
}

Controllable* QuestManager::getSelected() {
	return selectedDestination;
}