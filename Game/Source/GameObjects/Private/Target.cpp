//
// Created by tahan on 03/12/2023.
//

#include <SpriteComponent.h>
#include <RigidBody.h>
#include <BoxCollider.h>
#include <ResourceManager.h>
#include <random>
#include "../Public/Target.h"

Target::Target()
{

    // Create a random number generator engine
    std::random_device rd;  // Uses a hardware entropy source if available
    std::mt19937 gen(rd()); // Mersenne Twister engine with a default seed

    // Define a distribution (e.g., uniform distribution between 1 and 10)
    std::uniform_int_distribution<int> distributionX(0, 1920);
    std::uniform_int_distribution<int> distributionY(0, 1080);

    // Generate a random number
    int randomX = distributionX(gen);
    int randomY = distributionY(gen);
    setPosition((float)randomX, (float)randomY);

    AddComponentOfType<RigidBody>();
    AddComponentOfType<BoxCollider>();


    FindComponentOfType<RigidBody>()->SetBodyType(b2BodyType::b2_dynamicBody);
    if(auto Collider = FindComponentOfType<BoxCollider>())
    {
        Collider->SetSize(radius);
        Collider->SetDensity(10.f);
        Collider->SetFriction(100.f);
    }
}

void Target::BeginPlay() {
    GameObject::BeginPlay();


}

void Target::Tick(float DeltaTime) {
    GameObject::Tick(DeltaTime);

    if(auto SpriteComp = FindComponentOfType<SpriteComponent>()){
        SpriteComp->setScale(0.05, 0.05);
    }else{
        Texture texture = Texture();
        texture.loadFromFile(ResourceManager::GetInstance()->GetAssetPathByID("Target"));
        AddComponentOfType<SpriteComponent>(texture);
        FindComponentOfType<SpriteComponent>()->setScale(0.05, 0.05);
    }


    LifeTimeCounter += DeltaTime;
    if(LifeTimeCounter > LifeTime)
    {
        Destroy();
    }


}
