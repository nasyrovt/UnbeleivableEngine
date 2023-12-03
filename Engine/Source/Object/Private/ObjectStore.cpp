//
// Created by Nasyrov Takhir on 30/10/2023.
//

#include "../Public/ObjectStore.h"
#include "../Public/Object.h"
#include "../Public/GameObject/GameObject.h"
#include "../../GameFramework/Public/GameplayStatics.h"
#include "../../GameFramework/Public/Game.h"

ObjectStore::ObjectStore()
{

}

ObjectStore* ObjectStore::GetInstance()
{
    static ObjectStore instance; // Static instance
    return &instance;
}

void ObjectStore::AddObject(Object* InObject)
{
    Objects[InObject->GetUniqueId()] = InObject;
}

Object* ObjectStore::GetObjectById(int InUniqueId)
{
    if (Objects.find(InUniqueId) != Objects.end())
    {
        return Objects[InUniqueId];
    }
    return nullptr;
}

void ObjectStore::RemoveObject(Object* object)
{
    if (Objects.find(object->GetUniqueId()) != Objects.end())
    {
        Objects.erase(object->GetUniqueId());
    }
}

unordered_map<int, Object*> ObjectStore::GetObjects()
{
    return Objects;
}

unordered_map<int, GameObject*> ObjectStore::GetGameObjects()
{
    return GameObjects;
}

void ObjectStore::AddGameObject(GameObject* InObject)
{
    //In case object is added in runtime
    if(auto Game = GameplayStatics::GetGame())
    {
        if(Game->IsRunning())
        {
            InObject->Initialize();
            InObject->BeginPlay();
        }
    }

    GameObjects[InObject->GetUniqueId()] = InObject;
}

void ObjectStore::RemoveGameObject(GameObject* object)
{
    if (GameObjects.find(object->GetUniqueId()) != GameObjects.end())
    {
        GameObjects.erase(object->GetUniqueId());
    }
}
