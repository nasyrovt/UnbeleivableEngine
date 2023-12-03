//
// Created by Nasyrov Takhir on 02/11/2023.
//

#ifndef CUSTOMENGINE_COLLIDER_H
#define CUSTOMENGINE_COLLIDER_H


#include <box2d/b2_shape.h>
#include <box2d/b2_fixture.h>
#include "../Base/SceneComponent.h"
#include "../../../GameFramework/Public/Physics/ICollidable.h"

class Collider : public SceneComponent, public ICollidable
{
public:
	Collider();
	void InitializeComponent() override;
	void Tick(float DeltaTime) override;
	void LateTick(float DeltaTime) override;

	void OnCollisionEnter(Collision *InCollision) override;
	void OnCollisionExit(Collision *InCollision) override;

	void SetDensity(float InDensity);
	void SetFriction(float InFriction);
	void CreateFixture(b2Body* InBody);

	virtual b2Shape* GetCollisionShape() = 0;

protected:
	b2FixtureDef FixtureDef;
	b2Fixture* Fixture = nullptr;
};


#endif //CUSTOMENGINE_COLLIDER_H
