//
// Created by Nasyrov Takhir on 31/10/2023.
//

#ifndef CUSTOMENGINE_SCENECOMPONENT_H
#define CUSTOMENGINE_SCENECOMPONENT_H


#include "ActorComponent.h"
#include <SFML/Graphics.hpp>

class SceneComponent : public ActorComponent, public sf::Transformable, public sf::Drawable
{
public:
    SceneComponent();
    void Tick(float DeltaTime) override;
    void BeginPlay() override;
    void Activate() override;
    void Deactivate() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CUSTOMENGINE_SCENECOMPONENT_H
