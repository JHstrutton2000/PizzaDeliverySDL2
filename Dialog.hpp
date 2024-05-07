#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <vector>
#include <string>

class Dialog {
public:
	void addDialog(std::string dialog) {
		dialogs.push_back(dialog);
	}

	void addDialog(std::vector<std::string> dialog) {
		for (int i = 0; i < dialog.size(); i++) {
			dialogs.push_back(dialog[i]);
		}
	}

	void nextDialog() {
		if (dialogOpen) {
			readIndex++;
		}

		if (readIndex >= dialogs.size()) {
			readIndex = 0;

			if (dialogOpen) {
				closeDialog();
			}
			else {
				openDialog();
			}
		}
		else{
			dialogOpen = true;
		}
	}

	void prevDialog() {
		if (readIndex > 0) {
			readIndex--;
		}
	}

	std::string readDialog() {
		return dialogs[readIndex];
	}

	void closeDialog() {
		dialogOpen = false;
	}

	void openDialog() {
		dialogOpen = true;
	}
protected:
	bool dialogOpen = false;

private:
	std::vector<std::string> dialogs;
	int readIndex = 0;
};

#endif