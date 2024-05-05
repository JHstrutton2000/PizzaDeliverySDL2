#ifndef Quest_HPP
#define Quest_HPP

#include "SDL.h"
#include "Physics.hpp";
#include "questTypes.h"
#include <vector>


class Quest {
public:
	void addQuest(Physics* target, Physics* destination, questTypes type) {
		targets.push_back(target);
		destinations.push_back(destination);
		types.push_back(type);

		SDL_FRect tempPos = SDL_FRect{ 0, 0, 5, 5 };
		questPositions.push_back(tempPos);
	}

	void removeQuest(Physics* target) {
		int index = findQuest(target);

		if (index >= 0) {
			removeQuest(index);
		}
	}

	void updateQuest(Physics* target, questTypes type) {
		updateQuest(target, nullptr, type);
	}

	void updateQuest(Physics* target, Physics* destination, questTypes type) {
		int index = findQuest(target);

		if (index >= 0) {
			updateQuest(index, destination, type);
		}
	}

protected:
	void renderQuests(SDL_Renderer* renderer, float* offset) {
		for (int i = 0; i < types.size(); i++) {
			float* tempPos = nullptr;

			switch(types[i]) {
				case questTypes::deliver:
					tempPos = destinations[i]->getPosition();
					break;
				case questTypes::pickup:
					tempPos = targets[i]->getPosition();
					break;
			}

			if (tempPos) {
				questPositions[i].x = tempPos[0] + tempPos[2] / 2 - 2 - offset[0];
				questPositions[i].y = tempPos[1] - 10 - offset[1];

				SDL_SetRenderDrawColor(renderer, 20, 20, 20, 0x00);
				SDL_RenderFillRectF(renderer, &questPositions[i]);
			}
		}

	}

private:
	std::vector<questTypes> types;
	std::vector<Physics*> targets;
	std::vector<Physics*> destinations;
	std::vector<SDL_FRect> questPositions;

	int findQuest(Physics* target) {
		auto it = std::find(targets.begin(), targets.end(), target);

		if (it != targets.end()) {
			return std::distance(targets.begin(), it);
		}

		return -1;
	}

	void removeQuest(int index) {
		types.erase(types.begin() + index);
		targets.erase(targets.begin() + index);
		destinations.erase(destinations.begin() + index);
		questPositions.erase(questPositions.begin() + index);
	}

	void updateQuest(int index, Physics* destination, questTypes type) {
		types[index] = type;

		if (destination) {
			destinations[index] = destination;
		}
	}
};

#endif //Quest_HPP