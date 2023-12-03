//
// Created by Nasyrov Takhir on 01/11/2023.
//

#ifndef CUSTOMENGINE_RESOURCEMANAGER_H
#define CUSTOMENGINE_RESOURCEMANAGER_H

#include <iostream>
#include <unordered_map>
#include "yaml-cpp/yaml.h"


#define RESOURCECONFIGFILE "resources.yaml"
#define ENGINECONFIGFILE "engine.yaml"
#define GAMECONFIGFILE "game.yaml"
#define DEVELOPERCONFIGFILE "developer.yaml"

#define CONFIGFILES {RESOURCECONFIGFILE, ENGINECONFIGFILE, GAMECONFIGFILE, DEVELOPERCONFIGFILE}


using namespace std;


class ResourceManager
{

public:
	ResourceManager();

	static ResourceManager *GetInstance();

	void FetchConfigFiles();

	string GetAssetPathByID(string assetID);


	string GetEngineSetting(string setting);

private:
	unordered_map<string, YAML::Node> ConfigFiles;
};


#endif //CUSTOMENGINE_RESOURCEMANAGER_H
