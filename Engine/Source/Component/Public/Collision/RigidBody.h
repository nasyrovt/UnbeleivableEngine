//
// Created by Nasyrov Takhir on 02/11/2023.
//

#ifndef CUSTOMENGINE_RIGIDBODY_H
#define CUSTOMENGINE_RIGIDBODY_H


#include <box2d/b2_body.h>
#include "../Base/ActorComponent.h"


class RigidBody : public ActorComponent
{
public:
	RigidBody();

	void SetBodyType(b2BodyType InBodyType);
	void SetBodyPosition(const b2Vec2& position);
	void SetLinearVelocity(const b2Vec2& InVelocity);
	void SetAngularVelocity(float InVelocity);

	void BeginPlay() override;

	b2Body* GetBody();
	float GetBodyAngle();
	b2BodyType GetBodyType();
	b2Vec2 GetBodyPosition();
	b2Vec2 GetLinearVelocity();
	float GetAngularVelocity();

private:
	b2Body* Body = nullptr;
	b2BodyDef BodyDef;
};


#endif //CUSTOMENGINE_RIGIDBODY_H
