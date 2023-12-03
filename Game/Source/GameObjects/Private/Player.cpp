//
// Created by tahan on 29/11/2023.
//

#include "../Public/Player.h"
#include "GameFramework/Public/GameplayStatics.h"
#include "../Public/TargetSpawner.h"

#include <BoxCollider.h>
#include <RigidBody.h>
#include <SpriteComponent.h>
#include <ResourceManager.h>
#include <format>

Player::Player()
{

}

void Player::BeginPlay()
{
    GameObject::BeginPlay();

    AddComponentOfType<SpriteComponent>();
    setPosition(0, 0);
}

void Player::Tick(float DeltaTime)
{
    GameObject::Tick(DeltaTime);

//    Texture texture = Texture();
//    auto CounterText = std::format("Counter_", PointsCounter);
//    texture.loadFromFile(ResourceManager::GetInstance()->GetAssetPathByID(CounterText));
//    if(auto SpriteComp = FindComponentOfType<SpriteComponent>())
//    {
//        SpriteComp->SetTexture(texture, true);
//    }
}

void Player::HandleInput(sf::Event InEvent)
{
    GameObject::HandleInput(InEvent);

    if (InEvent.type == sf::Event::MouseButtonPressed)
    {
        if (InEvent.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition();
            if(Spawner)
            {
                auto TargetObjects = Spawner->GetActiveTargets();
                for(auto Target : TargetObjects)
                {
                    auto TargetPos = Target->getPosition();
                    auto HalfSide = Target->GetRadius() / 2;
                    auto XDiff = abs(float(mousePosition.x) - (TargetPos.x + HalfSide));
                    auto YDiff = abs(float(mousePosition.y) - (TargetPos.y + HalfSide));
                    if (XDiff <= HalfSide && YDiff < HalfSide)
                    {
                        Target->Destroy();
                        PointsCounter++;
                        cout << "Counter : " << PointsCounter << endl;
                    }
                }
            }
        }
    }
}

void Player::SetSpawner(TargetSpawner *InSpawner)
{
    Spawner = InSpawner;
}

