//
// Created by Nasyrov Takhir on 03/11/2023.
//

#ifndef CUSTOMENGINE_COLLISIONLISTENER_H
#define CUSTOMENGINE_COLLISIONLISTENER_H

#include <box2d/b2_world_callbacks.h>

class CollisionListener : public b2ContactListener
{
	friend class Physics;
public:
	void BeginContact(b2Contact *contact) override;
	void EndContact(b2Contact *contact) override;
private:
	static CollisionListener* GetInstance();
	CollisionListener();
};


#endif //CUSTOMENGINE_COLLISIONLISTENER_H
