//
// Created by tahan on 03/12/2023.
//

#ifndef GAME_TARGETSPAWNER_H
#define GAME_TARGETSPAWNER_H


#include <GameObject.h>
#include "Target.h"

class TargetSpawner : public GameObject
{
public:
    TargetSpawner();

    void BeginPlay() override;

    void Tick(float DeltaTime) override;

    std::vector<Target*> GetActiveTargets(){ return ActiveTargets; }

    friend class Player;
protected:
    float SpawnTimer = 0.f;
    float SpawnInterval = 1.f;

    void SpawnTargetObject();
    void RemoveTargetObject(Target* InTarget);

    std::vector<Target*> ActiveTargets;
};


#endif //GAME_TARGETSPAWNER_H
