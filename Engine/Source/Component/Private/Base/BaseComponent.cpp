//
// Created by Nasyrov Takhir on 30/10/2023.
//

#include "../../Public/Base/BaseComponent.h"

BaseComponent::BaseComponent()
{
    bCanEverTick = true;
}

void BaseComponent::BeginPlay()
{

}

void BaseComponent::Tick(float DeltaTime)
{
    if(!bCanEverTick || !bCanTick) return;
}

GameObject* BaseComponent::GetOwner() {
    return Owner;
}

void BaseComponent::SetOwner(GameObject* InGameObjectPtr)
{
    Owner = InGameObjectPtr;
}

void BaseComponent::LateTick(float DeltaTime)
{
    if(!bCanEverTick || !bCanTick) return;
}

void BaseComponent::EndPlay() {

}

void BaseComponent::Activate()
{
    if(!bCanEverTick) return;

    bCanTick = true;
}

void BaseComponent::Deactivate()
{
    bCanTick = false;
}

void BaseComponent::InitializeComponent()
{

}
