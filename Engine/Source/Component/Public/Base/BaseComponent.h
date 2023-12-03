//
// Created by Nasyrov Takhir on 30/10/2023.
//

#ifndef CUSTOMENGINE_BASECOMPONENT_H
#define CUSTOMENGINE_BASECOMPONENT_H


#include "../../../Object/Public/ITickable.h"

class BaseComponent : public ITickable
{

public:
    BaseComponent();

    virtual void BeginPlay();
    virtual void EndPlay();
    virtual void InitializeComponent();
    virtual void Activate();
    virtual void Deactivate();

    void Tick(float DeltaTime) override;
    void LateTick(float DeltaTime) override;

	//TODO: maybe need UID?
    //[[nodiscard]] int GetUID() const { return UID; }
	//void SetUID(int ID){ UID = ID; }

    void SetOwner(class GameObject* InGameObjectPtr);
    GameObject* GetOwner();

private:
    //int UID;
    GameObject* Owner;
};


#endif //CUSTOMENGINE_BASECOMPONENT_H
