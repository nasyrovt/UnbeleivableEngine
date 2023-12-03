//
// Created by Nasyrov Takhir on 02/11/2023.
//

#include <iostream>
#include <box2d/b2_world.h>
#include "../../Public/Collision/BoxCollider.h"
#include "../../../Object/Public/GameObject/GameObject.h"
#include "../../Public/Drawable/SpriteComponent.h"
#include "../../../GameFramework/Public/GameplayStatics.h"

BoxCollider::BoxCollider()
{
}

b2Shape *BoxCollider::GetCollisionShape()
{
//	if (auto Owner = GetOwner())
//	{
//		if (auto SpriteComp = Owner->FindComponentOfType<SpriteComponent>())
//		{
//			CollisionShape.SetAsBox(SpriteComp->GetSprite()->getLocalBounds().width/2, SpriteComp->GetSprite()->getLocalBounds().height/2);
//		}
//	}
	return &CollisionShape;
}

void BoxCollider::SetSize(float InSize)
{
	Size = InSize;
	CollisionShape.SetAsBox(InSize / 2, InSize / 2);
}

void BoxCollider::OnCollisionEnter(Collision *InCollision)
{
	std::cout << "Enter the collision!" << std::endl;
}

void BoxCollider::OnCollisionExit(Collision *InCollision)
{
	std::cout << "Exit the collision!" << std::endl;
}

void BoxCollider::draw(RenderTarget &target, sf::RenderStates states) const
{
	SceneComponent::draw(target, states);
}
