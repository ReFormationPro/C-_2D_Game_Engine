#include "AssetLoader.hpp"
#include "SDL2/SDL.h"
#define cJSON_GetObjectV(par1, par2) cJSON_GetObjectItemCaseSensitive(par1, par2)

namespace AssetLoader {
Camera MainCamera;
std::vector<SDL_Surface*> Surfaces;

//to get this file compile
SDL_PixelFormat* format;
SDL_Surface *loadOptimizedSurface(const char *path, SDL_PixelFormat *format);


bool LoadAssets() {
    
    return true;
}
bool loadLevelAssets(std::string levelName) {
    std::string levelDir = "levels/";
    cJSON *jsonData = NULL;
    cJSON *dataContainer = NULL, *tempObj = NULL;
    const char *level = (levelDir+levelName).c_str();

    printf("Loading assets of level \"%s\"\n", level);
    jsonData = loadJSON_File(level);

    dataContainer = cJSON_GetObjectV(jsonData, "camera_start");
    MainCamera.position.x = cJSON_GetObjectV(dataContainer, "x")->valuedouble;
    MainCamera.position.y = cJSON_GetObjectV(dataContainer, "y")->valuedouble;

    dataContainer = cJSON_GetObjectV(jsonData, "assets");
    cJSON_ArrayForEach(tempObj, dataContainer) { //Iterate over dataContainer like iterating array where current object is tempObj
        /* TODO Parse Assets */
        const char* str = cJSON_GetObjectV(tempObj, "kind")->valuestring;
        if (strcmp(str, "sprite")) {
            /*TODO: Create a Sprite class and store them instead */
            const char* name = cJSON_GetObjectV(tempObj, "name")->valuestring;
            SDL_Surface* surface = loadOptimizedSurface(""/*TODO: Image Path*/, format);
            Surfaces.push_back(surface);
        } else if (strcmp(str, "model")) {
            //
        }
    }
    dataContainer = cJSON_GetObjectV(jsonData, "objects");
    cJSON_ArrayForEach(tempObj, dataContainer) {
        const char* str = cJSON_GetObjectV(tempObj, "kind")->valuestring;
        if (strcmp(str, str)) {

        }
    }
    cJSON_Delete(jsonData);
    return true;
}
cJSON *loadJSON_File(const char* fPath) {
    FILE *jsonFile = fopen(fPath, "r");
    cJSON *jsonData = NULL;
    long size = 0;
    char *fcontent = NULL;
    
    if (!jsonFile) {
        printf("JSON File open failed.\n");/*TODO: Print errno */
        return NULL;
    }
    fseek(jsonFile, 0, SEEK_END);
    size = ftell(jsonFile);
    fseek(jsonFile, 0, SEEK_SET);
    fcontent = new char[size];//(char *) malloc(size);
    fread(fcontent, 1, size, jsonFile);
    jsonData = cJSON_Parse(fcontent);
    delete(fcontent);
    if (!jsonData) {
        const char *err = cJSON_GetErrorPtr();/*Where is this allocated?: Belongs to global scope, check source*/
        printf("cJSON Parse error. Error before:\n%s\n", err);
    }
    return jsonData;
}

SDL_Surface *loadOptimizedSurface(const char *path, SDL_PixelFormat *format) {
    SDL_Surface *optimizedSurface = NULL;
    SDL_Surface *originalSurface = SDL_LoadBMP(path);
    if (originalSurface == NULL) {
        printf( "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
    } else {
        //TODO
        optimizedSurface = SDL_ConvertSurface(originalSurface, format, 0);
        if (optimizedSurface == NULL) {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        SDL_FreeSurface(originalSurface);
    }
    return optimizedSurface;
}

}
