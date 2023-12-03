//
// Created by tahan on 03/12/2023.
//

#ifndef GAME_CARCOLLISION_H
#define GAME_CARCOLLISION_H


#include <BoxCollider.h>

class CarCollision : public BoxCollider
{
public:
    CarCollision();

    void BeginPlay() override;

    void Tick(float DeltaTime) override;


};


#endif //GAME_CARCOLLISION_H
