//
// Created by Nasyrov Takhir on 03/11/2023.
//

#ifndef CUSTOMENGINE_COLLISION_H
#define CUSTOMENGINE_COLLISION_H


#include <box2d/b2_body.h>

class RigidBody;


class Collision
{
public:
	Collision();
	Collision(b2Body* InMe, b2Body* InOther);

	void SetMyRigidBody(b2Body* InRigidBody);
	void SetOtherRigidBody(b2Body* InRigidBody);
	b2Body* GetMeRigidBody();
	b2Body* GetOtherRigidBody();
protected:
	b2Body* Me = nullptr;
	b2Body* Other = nullptr;
};


#endif //CUSTOMENGINE_COLLISION_H
