//
// Created by Nasyrov Takhir on 02/11/2023.
//
#pragma once

#ifndef CUSTOMENGINE_PHYSICS_H
#define CUSTOMENGINE_PHYSICS_H

#include <box2d/b2_world.h>
#include "../../../Object/Public/ITickable.h"
#include "../../../Component/Public/Collision/RigidBody.h"
#include "../../../Debug/Public/DrawHelper.h"
#include <unordered_map>

class GameObject;

class Physics : public ITickable
{
	friend class GameplayStatics;
public:

	b2World* GetWorld();
	void Tick(float DeltaTime) override;
	void LateTick(float DeltaTime) override;

	std::unordered_map<b2Body*, RigidBody*> GetPhysicObjects();
	void RegisterPhysicsObject(RigidBody* InObject);
	void UnregisterPhysicsObject(RigidBody* InObject);

	void SetGravity(b2Vec2 InGravity);
private:
	Physics();
	static Physics* GetInstance();

	//DrawHelper DrawDebugHelperObj;
	b2Vec2 Gravity;
	b2World World;

	std::unordered_map<b2Body*, RigidBody*> PhysicObjects;
};


#endif //CUSTOMENGINE_PHYSICS_H
