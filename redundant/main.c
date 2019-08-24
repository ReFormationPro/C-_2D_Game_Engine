#include "main.h"
#include "globals.h"
#include "load_assets.h"

#include "cjson/cJSON.h"

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;

int initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL VIDEO could not be initialized. Error: %s\n", SDL_GetError());
        return 0;
    } else {
        gWindow = SDL_CreateWindow("SDL Game Engine v0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (!gWindow) {
            printf("SDL Window could not be created. Error: %s\n", SDL_GetError());
        return 0;
        }
        gScreenSurface = SDL_GetWindowSurface(gWindow);
        return 1;
    }
}

extern Camera MainCamera;
int main(int argc, char **argv) {
    if (!initialize() || !loadAssets("test")) {
        return 0;
    } else {
        int loop = 1;
        SDL_Event e;
        while (loop) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) loop = 0;
                else if (e.type == SDL_KEYDOWN) {
                    /*TODO: Handle keys*/
                }
            }
        }
    }
    return 0;
}
