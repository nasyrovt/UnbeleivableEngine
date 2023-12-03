//
// Created by tahan on 03/12/2023.
//

#ifndef GAME_TARGET_H
#define GAME_TARGET_H


#include <GameObject.h>

class Target : public GameObject
{
public:
    Target();

    void BeginPlay() override;

    void Tick(float DeltaTime) override;
    float GetRadius() const{ return radius; }
private:
    float radius = 100.f;
    float LifeTime = 1.5f;
    float LifeTimeCounter = 0.f;
};


#endif //GAME_TARGET_H
