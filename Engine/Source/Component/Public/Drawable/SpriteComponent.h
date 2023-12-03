//
// Created by Nasyrov Takhir on 31/10/2023.
//

#ifndef CUSTOMENGINE_SPRITECOMPONENT_H
#define CUSTOMENGINE_SPRITECOMPONENT_H

#include <SFML/Graphics.hpp>
#include "../Base/SceneComponent.h"

using namespace sf;


class SpriteComponent : public SceneComponent
{
public:
    SpriteComponent();
    explicit SpriteComponent(const Sprite& InSprite);
    explicit SpriteComponent(const Texture& texture);
    explicit SpriteComponent(const Texture& texture, const IntRect& rectangle);


    void Tick(float DeltaTime) override;
    void LateTick(float DeltaTime) override;
    void BeginPlay() override;

    void SetDominantColor(const Color& color);
    void SetTexture(const sf::Texture &texture, bool bResetRect);
    void SetSmooth(bool bSmooth);

	const Sprite* GetSprite() const;

    void draw(RenderTarget &target, RenderStates states) const override;

private:
	Texture Texture;
    Sprite Sprite;

};


#endif //CUSTOMENGINE_SPRITECOMPONENT_H
