#include "globals.hpp"
#include "load_assets.hpp"

#define cJSON_GetObjectV(par1, par2) cJSON_GetObjectItemCaseSensitive(par1, par2)
class AssetLoader {
    public:
        static int loadLevelAssets(string levelName) {
            string levelDir = "levels/";
            cJSON *jsonData = NULL;
            cJSON *tempJson = NULL, *tempObj = NULL;

            printf("Loading assets of level \"%s\"\n", level);
            jsonData = loadJSON_File(levelDir+levelName);
            
            tempJson = cJSON_GetObjectV(jsonData, "camera_start");
            MainCamera.position.x = cJSON_GetObjectV(tempJson, "x")->valuedouble;
            MainCamera.position.y = cJSON_GetObjectV(tempJson, "y")->valuedouble;
            
            tempJson = cJSON_GetObjectV(jsonData, "assets");
            cJSON_ArrayForEach(tempObj, tempJson) {
                /* TODO Parse Assets */
            }
        }
}

class Assets {
    public:
        Camera MainCamera;
        Entity Entities[];
}
