#ifndef SceneManager_H
#define SceneManager_H

#include "Scene.h"
#include <vector>

class SceneManager {
public:
	void setActiveScene(Scene* scene);
	void update();
	void render();
	Scene* getActiveScene();
private:
	Scene* activeScene;
};

extern SceneManager* sceneManager;

#endif //SceneManager_H