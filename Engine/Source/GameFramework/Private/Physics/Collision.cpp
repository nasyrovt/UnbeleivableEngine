//
// Created by Nasyrov Takhir on 03/11/2023.
//

#include "../../Public/Physics/Collision.h"

void Collision::SetMyRigidBody(b2Body *InRigidBody)
{
	Me = InRigidBody;
}

void Collision::SetOtherRigidBody(b2Body *InRigidBody)
{
	Other = InRigidBody;
}

b2Body *Collision::GetMeRigidBody()
{
	return Me;
}

b2Body *Collision::GetOtherRigidBody()
{
	return Other;
}

Collision::Collision()
{

}

Collision::Collision(b2Body *InMe, b2Body *InOther) : Me(InMe), Other(InOther)
{

}
