//
// Created by Nasyrov Takhir on 01/11/2023.
//

#include "../Public/GameplayStatics.h"
#include "../Public/Game.h"
#include "../Public/Physics/Physics.h"



Game *GameplayStatics::GetGame()
{
	return Game::GetGame();
}

ObjectStore *GameplayStatics::GetObjectStore()
{
	return ObjectStore::GetInstance();
}

b2World *GameplayStatics::GetPhysicsWorld()
{
	return Physics::GetInstance()->GetWorld();
}

class Physics *GameplayStatics::GetPhysics()
{
	return Physics::GetInstance();
}
