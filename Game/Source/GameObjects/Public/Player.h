//
// Created by tahan on 29/11/2023.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <GameObject.h>
#include "../../Components/Public/CarCollision.h"
#include "TargetSpawner.h"

class RigidBody;


class Player : public GameObject
{
public:
    Player();

    void BeginPlay() override;

    void Tick(float DeltaTime) override;

    void HandleInput(sf::Event InEvent) override;
    void SetSpawner(TargetSpawner* InSpawner);
private:
    TargetSpawner* Spawner;
    int PointsCounter = 0;
};


#endif //GAME_PLAYER_H
