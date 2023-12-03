//
// Created by Nasyrov Takhir on 30/10/2023.
//

#include "../../Public/GameObject/GameObject.h"
#include "../../Public/ObjectStore.h"
#include "../../../GameFramework/Public/GameplayStatics.h"

GameObject::GameObject()
{
    bCanEverTick = true;
    //TODO: Avoid calling this function in constructor (virtual)
    RegisterToStore();
}

void GameObject::BeginPlay()
{
    Activate();
    for(const auto& Component : Components)
    {
        Component->BeginPlay();
    }
}

void GameObject::Tick(float DeltaTime)
{
    if(!bCanEverTick || !bCanTick) return;

    for(const auto& Component : Components)
    {
        Component->Tick(DeltaTime);
    }
}

void GameObject::LateTick(float DeltaTime)
{
    if(!bCanEverTick || !bCanTick) return;

    for(const auto& Component : Components)
    {
        Component->LateTick(DeltaTime);
    }
}

void GameObject::Activate()
{
    Object::Activate();
    if(bCanEverTick)
    {
        bCanTick = true;
    }
}

void GameObject::Deactivate()
{
    Object::Deactivate();
    bCanTick = false;
}

void GameObject::draw(RenderTarget &target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());
    for(const auto& Component : Components)
    {
        if(auto DrawableObjPtr = dynamic_pointer_cast<sf::Drawable>(Component))
        {
            target.draw(*DrawableObjPtr, states);
        }
    }
}

void GameObject::RegisterToStore()
{
    Object::RegisterToStore();

    if(auto ObjectStore = GameplayStatics::GetObjectStore())
    {
        ObjectStore->AddGameObject(this);
    }
}

void GameObject::UnregisterFromStore() {
    Object::UnregisterFromStore();

    if(auto ObjectStore = GameplayStatics::GetObjectStore())
    {
        ObjectStore->RemoveGameObject(this);
    }
}

void GameObject::EndPlay()
{
    Deactivate();
    for(const auto& Component : Components)
    {
        Component->EndPlay();
    }
}

void GameObject::Initialize()
{
    for(const auto& Component : Components)
    {
        Component->InitializeComponent();
    }
}

void GameObject::HandleInput(sf::Event InEvent)
{

}

void GameObject::Destroy() {
    UnregisterFromStore();
    Deactivate();
//    delete this;
}
