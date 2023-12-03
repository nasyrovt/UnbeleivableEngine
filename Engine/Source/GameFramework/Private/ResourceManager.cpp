//
// Created by Nasyrov Takhir on 01/11/2023.
//

#include <boost/filesystem.hpp>
#include "../Public/ResourceManager.h"

ResourceManager::ResourceManager() {

}

ResourceManager *ResourceManager::GetInstance() {
    static ResourceManager instance;
    return &instance;
}

void ResourceManager::FetchConfigFiles() {
    for (auto config: CONFIGFILES) {
        auto filePath = boost::filesystem::current_path().parent_path().string() + "\\Config\\" + config;
        ConfigFiles[config] = YAML::LoadFile(filePath);
        if (ConfigFiles[config].IsNull()) {
            cout << "Error Loading " + filePath << endl;
        }
    }
}

string ResourceManager::GetAssetPathByID(string assetID) {
    if (ConfigFiles[RESOURCECONFIGFILE]) {
        auto CurrentPath = boost::filesystem::current_path();
        if (ConfigFiles[RESOURCECONFIGFILE][assetID]) {
            auto TargetPath =
                    CurrentPath.generic_string() + "/Assets/" + ConfigFiles[RESOURCECONFIGFILE][assetID].as<string>();
            return TargetPath;
        }
    }
    return "";
}

string ResourceManager::GetEngineSetting(string setting) {
    if (ConfigFiles[ENGINECONFIGFILE]) {
        if (ConfigFiles[ENGINECONFIGFILE][setting]) {
            return ConfigFiles[ENGINECONFIGFILE][setting].as<string>();
        }
    }
    return "";
}


