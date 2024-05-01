#include <SDL.h>
#include <iostream>

#include "RenderManager.h"
#include "ControllerManager.h"
#include "physicsManager.h"
#include "InteractableManager.h"

#include "Car.h"
#include "Person.h"
#include "Building.h"

#define PhysicsUpdate 10

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool quit = false;

    SDL_Event event;

    Car* car = new Car(
        new SDL_FRect{ 100, 100 }
    );

    Person* person = new Person(
        new SDL_FRect{ 200, 100 }
    );

    Building* building = new Building(
        new SDL_FRect{ 400, 200 }
    );

    renderManager = new RenderManager();
    renderManager->addObject(car);
    renderManager->addObject(person);
    renderManager->addObject(building);

    physicsManager = new PhysicsManager();
    physicsManager->addObject(car);
    physicsManager->addObject(person);

    controllerManager = new ControllerManager();
    controllerManager->AssignControlledObject(person);

    interactableManager = new InteractableManager();
    interactableManager->addObject(car);
    interactableManager->addObject(person);
    //interactableManager->addObject(building);

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

            count = 0;
        }

        renderManager->render();
        count++;

        //SDL_Delay(1);
    }

    SDL_Quit();

    return 0;
}
