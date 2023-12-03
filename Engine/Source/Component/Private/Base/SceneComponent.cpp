//
// Created by Nasyrov Takhir on 31/10/2023.
//

#include "../../Public/Base/SceneComponent.h"

SceneComponent::SceneComponent()
{
    bCanEverTick = true;
}

void SceneComponent::BeginPlay() {
    ActorComponent::BeginPlay();
}

void SceneComponent::Tick(float DeltaTime) {
    BaseComponent::Tick(DeltaTime);

}

void SceneComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void SceneComponent::Activate() {
    ActorComponent::Activate();
}

void SceneComponent::Deactivate() {
    ActorComponent::Deactivate();
}
