//
// Created by Nasyrov Takhir on 03/11/2023.
//

#include "../../Public/Physics/CollisionListener.h"
#include "../../Public/Physics/Collision.h"
#include "../../Public/GameplayStatics.h"
#include "../../Public/Physics/Physics.h"
#include "../../../Object/Public/GameObject/GameObject.h"
#include "../../../Component/Public/Collision/Collider.h"

#include <vector>
#include <box2d/b2_contact.h>

CollisionListener::CollisionListener()
{

}

CollisionListener* CollisionListener::GetInstance()
{
	static CollisionListener Instance;
	return &Instance;
}

void CollisionListener::BeginContact(b2Contact *contact)
{
	b2ContactListener::BeginContact(contact);
	Collision CurrentCollision(
			contact->GetFixtureA()->GetBody(),
			contact->GetFixtureB()->GetBody());

	auto PhysicsObjects = GameplayStatics::GetPhysics()->GetPhysicObjects();
	if(auto Owner = PhysicsObjects[contact->GetFixtureA()->GetBody()]->GetOwner())
	{
		auto Colliders = Owner->FindComponentsOfType<Collider>();

		if(!Colliders.empty())
		{
			for(const auto& Collider : Colliders){
				Collider->OnCollisionEnter(&CurrentCollision);
			}
		}
	}
}

void CollisionListener::EndContact(b2Contact *contact)
{
	b2ContactListener::EndContact(contact);

	Collision CurrentCollision(
			contact->GetFixtureA()->GetBody(),
			contact->GetFixtureB()->GetBody());

	auto PhysicsObjects = GameplayStatics::GetPhysics()->GetPhysicObjects();
	if(auto Owner = PhysicsObjects[contact->GetFixtureA()->GetBody()]->GetOwner())
	{
		auto Colliders = Owner->FindComponentsOfType<Collider>();

		if(!Colliders.empty())
		{
			for(const auto& Collider : Colliders){
				Collider->OnCollisionExit(&CurrentCollision);
			}
		}
	}
}
