#include "main.hpp"
#include "cJSON/cJSON.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include "AssetLoader.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;

bool Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL VIDEO could not be initialized. Error: %s\n", SDL_GetError());
        return false;
    }
    gWindow = SDL_CreateWindow("SDL Game Engine v0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!gWindow) {
        printf("SDL Window could not be created. Error: %s\n", SDL_GetError());
        return 0;
    }
    gScreenSurface = SDL_GetWindowSurface(gWindow);
    return true;
}
extern void test();
int main(int argc, char **argv) {
    if (!Initialize() || !AssetLoader::LoadAssets()) {
        printf("Initialize or Asset Loading Error\n");
        return 0;
    }
    bool loop = true;
    SDL_Event e;
    test();
    while (loop) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) loop = 0;
            else if (e.type == SDL_KEYDOWN) {
                /*TODO: Input Received */
            }
        }
    }
    return 0;
}
