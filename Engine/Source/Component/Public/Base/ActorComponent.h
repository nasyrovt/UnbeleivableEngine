//
// Created by Nasyrov Takhir on 31/10/2023.
//

#ifndef CUSTOMENGINE_ACTORCOMPONENT_H
#define CUSTOMENGINE_ACTORCOMPONENT_H


#include "BaseComponent.h"

class ActorComponent : public BaseComponent
{
public:
    ActorComponent();

    void Tick(float DeltaTime) override;
    void BeginPlay() override;
    void Activate() override;
    void Deactivate() override;
};


#endif //CUSTOMENGINE_ACTORCOMPONENT_H
