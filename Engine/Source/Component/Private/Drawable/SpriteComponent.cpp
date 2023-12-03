//
// Created by Nasyrov Takhir on 31/10/2023.
//


#include <SFML/Graphics.hpp>
#include "../../Public/Drawable/SpriteComponent.h"

SpriteComponent::SpriteComponent()
{
    bCanEverTick = true;
    Texture = sf::Texture();
    Sprite = sf::Sprite(Texture);
}

SpriteComponent::SpriteComponent(const sf::Sprite& InSprite)
{
    bCanEverTick = true;
    Sprite = InSprite;
}

SpriteComponent::SpriteComponent(const sf::Texture &texture)
{
    bCanEverTick = true;
    Texture = texture;
    Sprite = sf::Sprite(texture);
}

SpriteComponent::SpriteComponent(const sf::Texture &texture, const IntRect &rectangle)
{
    bCanEverTick = true;
    Texture = texture;
    Sprite = sf::Sprite(texture, rectangle);
}

void SpriteComponent::BeginPlay()
{
    SceneComponent::BeginPlay();

}

void SpriteComponent::Tick(float DeltaTime)
{
    SceneComponent::Tick(DeltaTime);
}

void SpriteComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform.combine(getTransform());

    target.draw(Sprite, states);
}

void SpriteComponent::LateTick(float DeltaTime) {

}

void SpriteComponent::SetDominantColor(const Color &color)
{
    Sprite.setColor(color);
}

void SpriteComponent::SetTexture(const sf::Texture &texture, bool bResetRect)
{
    Texture = texture;
    Sprite.setTexture(Texture, bResetRect);
}

void SpriteComponent::SetSmooth(bool bSmooth)
{
    Texture.setSmooth(true);
}

const Sprite *SpriteComponent::GetSprite() const
{
	return &Sprite;
}
