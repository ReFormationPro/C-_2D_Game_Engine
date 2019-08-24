#include "globals.h"
#include "load_assets.h"

#define cJSON_GetObjectV(par1, par2) cJSON_GetObjectItemCaseSensitive(par1, par2)
Camera MainCamera;

int loadAssets(const char *level) {
    char levelPath[25] = "levels/";
    cJSON *jsonData = NULL;
    cJSON *tempJson = NULL, *tempObj = NULL;

    printf("Loading assets of level \"%s\"\n", level);
    strcat(levelPath, level);
    jsonData = loadJSON_File(levelPath);

    tempJson = cJSON_GetObjectV(jsonData, "camera_start");
    MainCamera.position.x = cJSON_GetObjectV(tempJson, "x")->valuedouble;
    MainCamera.position.y = cJSON_GetObjectV(tempJson, "y")->valuedouble;
    
    tempJson = cJSON_GetObjectV(jsonData, "assets");
    cJSON_ArrayForEach(tempObj, tempJson) {
        /*TODO: Parse asset*/
        
    }
    tempJson = cJSON_GetObjectV(tempJson, "objects");
    cJSON_ArrayForEach(tempObj, tempJson) {
        const char *kind = cJSON_GetObjectV(tempObj, "kind")->valuestring;
        void *obj = NULL;
        printf("parsing object of kind: %s\n", kind);
        if (strcmp(kind, "player") || strcmp(kind, "npc")) { 
            obj = malloc(sizeof(Animated));
            ((Animated *) obj)->position.x = cJSON_GetObjectV(cJSON_GetObjectV(tempObj, "pos"), "x")->valuedouble;
            ((Animated *) obj)->position.y = cJSON_GetObjectV(cJSON_GetObjectV(tempObj, "pos"), "y")->valuedouble;
            /*LevelManager.objects.pushObj(obj);*/
        } else if (strcmp(kind, "block")) {
            
        } else {
            printf("Object kind is unknown: \"%s\"", kind);
        }
    }

    cJSON_Delete(jsonData);
    return 1;
}

cJSON *loadJSON_File(const char *fPath) {
    FILE *jsonFile = fopen(fPath, "r");
    cJSON *jsonData = NULL;
    long size = 0;    
    char *fcontent = NULL;
    
    if (!jsonFile) {
        printf("JSON File open failed.\n"); /*TODO: Print errno */
        return NULL;
    }
    fseek(jsonFile, 0, SEEK_END);
    size = ftell(jsonFile);
    fseek(jsonFile, 0, SEEK_SET);
    fcontent = (char *) malloc(size);
    fread(fcontent, 1, size, jsonFile);
    jsonData = cJSON_Parse(fcontent);
    free(fcontent);
    if (!jsonData) {
        const char *err = cJSON_GetErrorPtr();/*Where is this allocated?*/
        printf("cJSON Parse error. Error before:\n%s\n", err);
    }
    return jsonData;
}
