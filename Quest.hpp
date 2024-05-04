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
	void renderQuests(SDL_Renderer* renderer) {
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
				SDL_FRect* pos = new SDL_FRect{ tempPos[0] + tempPos[2] / 2 - 2, tempPos[1] - 10, 5, 5 };

				SDL_SetRenderDrawColor(renderer, 20, 20, 20, 0x00);
				SDL_RenderFillRectF(renderer, pos);
			}
		}

	}

private:
	std::vector<questTypes> types;
	std::vector<Physics*> targets;
	std::vector<Physics*> destinations;

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
	}

	void updateQuest(int index, Physics* destination, questTypes type) {
		types[index] = type;

		if (destination) {
			destinations[index] = destination;
		}
	}
};

#endif //Quest_HPP