#ifndef Quest_HPP
#define Quest_HPP

#include "Physics.hpp";
#include "Quest.types"
#include <vector>

class Quest {
public:
	void removeQuest(Physics* target) {
		int index = findQuest(target);

		if (index >= 0) {
			removeQuest(index);
		}
	}

	void addQuest(Physics* target, questTypes type) {
		targets.push_back(target);
		types.push_back(type);
	}

	void updateQuest(Physics* target, questTypes type) {
		int index = findQuest(target);

		if (index >= 0) {
			updateQuest(index, type);
		}
	}

private:

	std::vector<questTypes> types;
	std::vector<Physics*> targets;

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
	}

	void updateQuest(int index, questTypes type) {
		types[index] = type;
	}
};

#endif //Quest_HPP