//
// Created by Nasyrov Takhir on 30/10/2023.
//

#ifndef CUSTOMENGINE_OBJECTSTORE_H
#define CUSTOMENGINE_OBJECTSTORE_H

#include <iostream>
#include <unordered_map>

class Object;
class GameObject;

using namespace std;

class ObjectStore{
    friend class GameplayStatics;
public:
    // Store a game object with a unique ID.
    void AddObject(Object* object);
    void RemoveObject(Object* object);
    void AddGameObject(GameObject* object);
    void RemoveGameObject(GameObject* object);

    unordered_map<int, Object*> GetObjects();
    unordered_map<int, GameObject*> GetGameObjects();
    // Retrieve a game object by its unique ID.
    Object* GetObjectById(int InUniqueId);

    int GetNextUniqueId(){ return ++uniqueIdCounter; }

protected:
    // Access the shared instance of ObjectStore.
    static ObjectStore* GetInstance();
private:
    ObjectStore(); // Private constructor to prevent external instantiation

    unordered_map<int, Object*> Objects;
    unordered_map<int, GameObject*> GameObjects;

    int uniqueIdCounter = 0;
};


#endif //CUSTOMENGINE_OBJECTSTORE_H
