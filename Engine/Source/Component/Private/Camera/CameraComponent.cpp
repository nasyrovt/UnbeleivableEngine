//
// Created by Nasyrov Takhir on 31/10/2023.
//

#include "../../Public/Camera/CameraComponent.h"
#include "../../../GameFramework/Public/Game.h"
#include "../../../GameFramework/Public/GameplayStatics.h"


CameraComponent::CameraComponent()
{
    if(Game* Game = GameplayStatics::GetGame())
    {
        View = Game->GetDefaultView();
    }
}

void CameraComponent::BeginPlay()
{
    SceneComponent::BeginPlay();
}

void CameraComponent::Tick(float DeltaTime)
{
    SceneComponent::Tick(DeltaTime);
}

void CameraComponent::EndPlay()
{
    BaseComponent::EndPlay();
}

void CameraComponent::UpdateCameraView()
{
    if(auto Game = GameplayStatics::GetGame())
    {
        Game->SetWindowView(&View);
    }
}

void CameraComponent::LateTick(float DeltaTime)
{
    BaseComponent::LateTick(DeltaTime);
    UpdateCameraView();
}

void CameraComponent::SetViewCenter(float x, float y)
{
    View.setCenter(x, y);
}

void CameraComponent::SetViewSize(float width, float height)
{
    View.setSize(width, height);
}

void CameraComponent::SetZoom(float zoomFactor)
{
    View.zoom(zoomFactor);
}

void CameraComponent::SetViewRotation(float angle)
{
    View.setRotation(angle);
}

void CameraComponent::SetViewport(const FloatRect &viewport)
{
    View.setViewport(viewport);
}

