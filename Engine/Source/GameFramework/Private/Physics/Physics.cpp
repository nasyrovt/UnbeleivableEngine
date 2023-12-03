//
// Created by Nasyrov Takhir on 02/11/2023.
//

#include "../../Public/Physics/Physics.h"
#include "../../Public/GameplayStatics.h"
#include "../../Public/Physics/CollisionListener.h"
#include "../../../Object/Public/ObjectStore.h"
#include "../../../Object/Public/GameObject/GameObject.h"
#include <box2d/b2_world.h>

Physics::Physics() : Gravity(0.f, 20.f), World(Gravity)
{
	World.SetContactListener(CollisionListener::GetInstance());
//	DrawDebugHelperObj.AppendFlags(b2Draw::e_shapeBit);
//	World.SetDebugDraw(&DrawDebugHelperObj);
}

b2World *Physics::GetWorld()
{
	return &World;
}

void Physics::Tick(float DeltaTime)
{

}

void Physics::LateTick(float DeltaTime)
{
	for (auto KVP: PhysicObjects)
	{
		if (auto Object = KVP.second->GetOwner())
		{
			if (auto rigidBody = Object->FindComponentOfType<RigidBody>())
			{
				rigidBody->SetBodyPosition(
						b2Vec2(Object->getPosition().x, Object->getPosition().y));
			}
		}
	}

	World.Step(DeltaTime, 8, 3);

	for (auto KVP: PhysicObjects)
	{
		if (auto Object = KVP.second->GetOwner())
		{
			if (auto rigidBody = Object->FindComponentOfType<RigidBody>())
			{
				Object->setPosition(rigidBody->GetBodyPosition().x, rigidBody->GetBodyPosition().y);
			}
		}
	}

}

void Physics::SetGravity(b2Vec2 InGravity)
{
	Gravity = InGravity;
	World.SetGravity(Gravity);
}

Physics *Physics::GetInstance()
{
	static Physics instance;
	return &instance;
}


void Physics::RegisterPhysicsObject(RigidBody *InObject)
{
	PhysicObjects[InObject->GetBody()] = InObject;
}

void Physics::UnregisterPhysicsObject(RigidBody *InObject)
{
	PhysicObjects.erase(InObject->GetBody());
}

std::unordered_map<b2Body *, RigidBody *> Physics::GetPhysicObjects()
{
	return PhysicObjects;
}
