//
// Created by Nasyrov Takhir on 02/11/2023.
//

#include "../../Public/Collision/RigidBody.h"
#include "../../../GameFramework/Public/Physics/Physics.h"
#include "../../../GameFramework/Public/GameplayStatics.h"

RigidBody::RigidBody()
{
	BodyDef = b2BodyDef();
	Body = GameplayStatics::GetPhysicsWorld()->CreateBody(&BodyDef);
}

void RigidBody::SetBodyType(b2BodyType InBodyType)
{
	Body->SetType(InBodyType);
}

void RigidBody::SetBodyPosition(const b2Vec2& position)
{
	Body->SetTransform(position, Body->GetTransform().q.GetAngle());
}

void RigidBody::SetLinearVelocity(const b2Vec2& InVelocity)
{
	Body->SetLinearVelocity(InVelocity);
}

void RigidBody::SetAngularVelocity(float InVelocity)
{
	Body->SetAngularVelocity(InVelocity);
}

b2Body *RigidBody::GetBody()
{
	return Body;
}

b2BodyType RigidBody::GetBodyType()
{
	return Body->GetType();
}

b2Vec2 RigidBody::GetBodyPosition()
{
	return Body->GetTransform().p;
}

b2Vec2 RigidBody::GetLinearVelocity()
{
	return Body->GetLinearVelocity();
}

float RigidBody::GetAngularVelocity()
{
	return Body->GetAngularVelocity();
}

float RigidBody::GetBodyAngle()
{
	return Body->GetTransform().q.GetAngle();
}

void RigidBody::BeginPlay()
{
	ActorComponent::BeginPlay();

	if(auto Physics = GameplayStatics::GetPhysics())
	{
		if(auto Owner = GetOwner())
		{
			Physics->RegisterPhysicsObject(this);
		}
	}
}
