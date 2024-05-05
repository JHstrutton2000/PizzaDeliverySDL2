#include <SDL.h>
#include <iostream>

#include "Scene.h"

#include "ControllerManager.h"
#include "SceneManager.h"

#include "Door.h"

#include "Car.h"
#include "Person.h"
#include "Building.h"
#include "Pizza.h"

#define PhysicsUpdate 10

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window;
    SDL_Renderer* renderer;
    
    window = SDL_CreateWindow("Pizza Delivery", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    bool quit = false;

    SDL_Event event;

    sceneManager = new SceneManager();
    controllerManager = new ControllerManager();

    Scene* mainScene = new Scene(window, renderer);
    Scene* indoor = new Scene(window, renderer, new SDL_Color{ 0xBE, 0x97, 0x5B, 0 });

    Door* indoorDoor= new Door(indoor, mainScene, new SDL_FRect{ 100, 100 });
    
    sceneManager->setActiveScene(mainScene);

    Car* car = new Car(
        mainScene,
        new SDL_FRect{ 100, 100 }
    );

    Person* player = new Person(
        mainScene,
        new SDL_FRect{ 200, 100 }
    );

    mainScene->setFollowPos(player->getPosition());

    for (float i = 50; i < 700; i+=200) {
        Door* door1 = new Door(mainScene, indoor, new SDL_FRect{ i + 50, 305 });

        mainScene->questManager->addDestination(new Building(
            mainScene,
            new SDL_FRect{ i, 200 }
        ));

        door1->setOutDoor(indoorDoor);
        indoorDoor->setOutDoor(door1);

        Door * door2 = new Door(mainScene, indoor, new SDL_FRect{ i + 50, 505 });
        mainScene->questManager->addDestination(new Building(
            mainScene,
            new SDL_FRect{ i, 400 }
        ));

        door2->setOutDoor(indoorDoor);
    }

    mainScene->renderManager->addUIObject(player);
    mainScene->questManager->assignObject(player);

    controllerManager->AssignObject(player);

    new Pizza(
        mainScene,
        new SDL_FRect{ 100, 20 }
    );

    new Pizza(
        mainScene,
        new SDL_FRect{ 150, 20}
    );

    new Pizza(
        mainScene,
        new SDL_FRect{ 200, 20 }
    );

    new Pizza(
        mainScene,
        new SDL_FRect{ 250, 20 }
    );

    int count = 0;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {

            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        quit = true;
                    }

                    controllerManager->keyDown(&event.key);
                    break;
                case SDL_KEYUP:
                    controllerManager->keyUp(&event.key);
                    break;
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }

        if (count >= PhysicsUpdate) {
            controllerManager->update();
            sceneManager->update();

            count = 0;
        }
        sceneManager->render();
        count++;

        SDL_RenderPresent(renderer);
        //SDL_Delay(1);
    }

    SDL_Quit();

    return 0;
}
