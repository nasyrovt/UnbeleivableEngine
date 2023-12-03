//
// Created by Nasyrov Takhir on 03/11/2023.
//

#ifndef CUSTOMENGINE_ICOLLIDABLE_H
#define CUSTOMENGINE_ICOLLIDABLE_H


#include "Collision.h"

class ICollidable
{
public:
	virtual void OnCollisionEnter(Collision* InCollision) = 0;
	virtual void OnCollisionExit(Collision *InCollision) = 0;
};


#endif //CUSTOMENGINE_ICOLLIDABLE_H
