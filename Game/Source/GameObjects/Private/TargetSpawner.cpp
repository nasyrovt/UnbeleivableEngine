//
// Created by tahan on 03/12/2023.
//

#include "../Public/TargetSpawner.h"

TargetSpawner::TargetSpawner() {

}

void TargetSpawner::BeginPlay() {
    GameObject::BeginPlay();
}

void TargetSpawner::Tick(float DeltaTime) {
    GameObject::Tick(DeltaTime);
    SpawnTimer += DeltaTime;

    if(SpawnTimer>= SpawnInterval){
        SpawnTargetObject();
        SpawnTimer = 0.f;
    }
}

void TargetSpawner::SpawnTargetObject()
{
    auto TargetObj = new Target();
    ActiveTargets.push_back(TargetObj);
}

void TargetSpawner::RemoveTargetObject(Target* InTarget)
{
    auto found = std::find(ActiveTargets.begin(), ActiveTargets.end(), InTarget);

    if (found != ActiveTargets.end()) {
        //Element is present in the vector
        ActiveTargets.erase(found);
    }
}
