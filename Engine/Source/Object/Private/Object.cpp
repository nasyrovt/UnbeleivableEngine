//
// Created by Nasyrov Takhir on 30/10/2023.
//

#include "../Public/Object.h"
#include "../Public/ObjectStore.h"
#include "../../GameFramework/Public/GameplayStatics.h"


Object::Object()
{
    if(auto ObjectStore = GameplayStatics::GetObjectStore())
    {
        uniqueId = ObjectStore->GetNextUniqueId();
        ObjectStore->AddObject(this);
    }

}

int Object::GetUniqueId() const  {
    return uniqueId;
}

void Object::RegisterToStore()
{
    GameplayStatics::GetObjectStore()->AddObject(this);
}

void Object::UnregisterFromStore()
{
    GameplayStatics::GetObjectStore()->RemoveObject(this);
}

void Object::Deactivate()
{
    bIsActive = false;
}

void Object::Activate()
{
    bIsActive = true;
}

void Object::Initialize()
{

}

void Object::Destroy()
{
    UnregisterFromStore();
    delete this;
}
