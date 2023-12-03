//
// Created by tahan on 03/12/2023.
//

#include "../Public/CarCollision.h"

CarCollision::CarCollision()
{
    SetSize(50);
}

void CarCollision::BeginPlay() {
    SceneComponent::BeginPlay();
}


void CarCollision::Tick(float DeltaTime) {
    Collider::Tick(DeltaTime);
}
