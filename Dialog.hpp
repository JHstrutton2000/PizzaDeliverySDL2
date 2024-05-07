#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <vector>
#include <string>

class Dialog {
public:
	void addDialog(std::string dialog) {
		dialogs.push_back(dialog);
	}

	std::string readNext() {
		std::string response = dialogs[readIndex];

		readIndex++;

		if (readIndex >= dialogs.size()) {
			readIndex = 0;
		}

		return response;
	}

protected:
	std::vector<std::string> dialogs;
	int readIndex = 0;
};

#endif