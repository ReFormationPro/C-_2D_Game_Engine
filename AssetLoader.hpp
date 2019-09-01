#include "cjson/cJSON.h"
#include <stdio.h>
#include <string>
#include <vector>

namespace AssetLoader {
    bool LoadAssets();
    cJSON *loadJSON_File(const char* fPath);

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

}
