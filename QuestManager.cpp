#include "QuestManager.h"
#include "Building.h"
#include <ctime> 

QuestManager::QuestManager() {
	addDestination(new Building(
		new SDL_FRect{ 50, 200 }
	));

	addDestination(new Building(
		new SDL_FRect{ 50, 400 }
	));


	addDestination(new Building(
		new SDL_FRect{ 200, 200 }
	));

	addDestination(new Building(
		new SDL_FRect{ 200, 400 }
	));


	addDestination(new Building(
		new SDL_FRect{ 350, 200 }
	));

	addDestination(new Building(
		new SDL_FRect{ 350, 400 }
	));


	addDestination(new Building(
		new SDL_FRect{ 500, 200 }
	));

	addDestination(new Building(
		new SDL_FRect{ 500, 400 }
	));


	addDestination(new Building(
		new SDL_FRect{ 650, 200 }
	));

	addDestination(new Building(
		new SDL_FRect{ 650, 400 }
	));
}

void QuestManager::addDestination(Controllable* object){
	questDestinations.push_back(object);
}

void QuestManager::assignObject(Quest* object) {
	assigned = object;
}

void QuestManager::assignQuest(Pickup* object) {
	srand((unsigned)time(0));

	int randomIndex = rand() % questDestinations.size();

	selectedDestination = questDestinations[randomIndex];

	assigned->addQuest(object, selectedDestination, questTypes::pickup);
}

Controllable* QuestManager::getSelected() {
	return selectedDestination;
}

QuestManager* questManager = nullptr;