#include <SDL.h>
#include <iostream>

#include "QuestManager.h"
#include "RenderManager.h"
#include "ControllerManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"
#include "collisionManager.h"

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

    bool quit = false;

    SDL_Event event;

    renderManager = new RenderManager();
    physicsManager = new PhysicsManager();
    collisionManager = new CollisionManager();
    controllerManager = new ControllerManager();
    interactableManager = new InteractableManager();

    questManager = new QuestManager();


    Car* car = new Car(
        new SDL_FRect{ 100, 100 }
    );

    Person* player = new Person(
        new SDL_FRect{ 200, 100 }
    );

    renderManager->addUIObject(player);
    controllerManager->AssignObject(player);
    questManager->assignObject(player);

    new Pizza(
        new SDL_FRect{ 100, 20 }
    );

    new Pizza(
        new SDL_FRect{ 150, 20}
    );

    new Pizza(
        new SDL_FRect{ 200, 20 }
    );

    new Pizza(
        new SDL_FRect{ 250, 20 }
    );



    //player->addQuest(pizza, building, questTypes::pickup);


    //person->pickup(pizza);


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
            physicsManager->update();
            controllerManager->update();
            collisionManager->update();

            count = 0;
        }

        renderManager->render();
        count++;

        //SDL_Delay(1);
    }

    SDL_Quit();

    return 0;
}
