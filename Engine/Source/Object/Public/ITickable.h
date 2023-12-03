//
// Created by Nasyrov Takhir on 30/10/2023.
//

#ifndef CUSTOMENGINE_ITICKABLE_H
#define CUSTOMENGINE_ITICKABLE_H


class ITickable {

public:
    virtual void Tick(float DeltaTime) = 0;
    virtual void LateTick(float DeltaTime) = 0;

protected:
    bool bCanEverTick = true;
    bool bCanTick = true;
};


#endif //CUSTOMENGINE_ITICKABLE_H
