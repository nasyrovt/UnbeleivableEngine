//
// Created by Nasyrov Takhir on 31/10/2023.
//

#ifndef CUSTOMENGINE_CAMERACOMPONENT_H
#define CUSTOMENGINE_CAMERACOMPONENT_H


#include "../Base/SceneComponent.h"


class CameraComponent : public SceneComponent
{
public:
    CameraComponent();

    void Tick(float DeltaTime) override;
    void LateTick(float DeltaTime) override;
    void BeginPlay() override;
    void EndPlay() override;

    void SetViewCenter(float x, float y);
    void SetViewSize(float width, float height);
    void SetViewport(const sf::FloatRect &viewport);
    void SetViewRotation(float angle);
    void SetZoom(float zoom);

protected:
    virtual void UpdateCameraView();

    class sf::View View;
};


#endif //CUSTOMENGINE_CAMERACOMPONENT_H
