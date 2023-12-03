//
// Created by Nasyrov Takhir on 02/11/2023.
//

#include "../../Public/Collision/Collider.h"
#include "../../../Object/Public/GameObject/GameObject.h"
#include "../../Public/Collision/RigidBody.h"

Collider::Collider() : Fixture(nullptr)
{

}

void Collider::Tick(float DeltaTime)
{
	SceneComponent::Tick(DeltaTime);
}

void Collider::LateTick(float DeltaTime)
{
	BaseComponent::LateTick(DeltaTime);
}

void Collider::SetFriction(float InFriction)
{
	FixtureDef.friction = InFriction;
	if (Fixture)
	{
		Fixture->SetFriction(InFriction);
	}
}

void Collider::SetDensity(float InDensity)
{
	FixtureDef.density = InDensity;
	if (Fixture)
	{
		Fixture->SetDensity(InDensity);
	}
}

void Collider::CreateFixture(b2Body *InBody)
{
	FixtureDef.shape = GetCollisionShape();
	Fixture = InBody->CreateFixture(&FixtureDef);
}

void Collider::InitializeComponent()
{
	BaseComponent::InitializeComponent();

	if (auto Owner = GetOwner())
	{
		if (auto rigidBody = Owner->FindComponentOfType<RigidBody>())
		{
			CreateFixture(rigidBody->GetBody());
		}
	}
}

void Collider::OnCollisionEnter(Collision *InCollision)
{

}

void Collider::OnCollisionExit(Collision *InCollision)
{

}

