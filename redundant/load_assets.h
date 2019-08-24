#include <stdio.h>
#include <SDL2/SDL.h>
#include "cjson/cJSON.h"

cJSON *loadJSON_File(const char *);
int loadAssets(const char *);

typedef struct {
    double x;
    double y;
} Position;

typedef struct {int todo;} Model;

typedef struct {
    Position position;

} Camera;
    
typedef struct {
    Position position;
    Model *model;

} Animated;

