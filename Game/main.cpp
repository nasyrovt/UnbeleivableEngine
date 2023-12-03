#include <iostream>
#include <Game.h>
#include <GameplayStatics.h>
#include <GameObject.h>
#include <SpriteComponent.h>
#include <RigidBody.h>
#include <BoxCollider.h>
#include <ResourceManager.h>
#include "Source/GameObjects/Public/Player.h"
#include "Source/GameObjects/Public/TargetSpawner.h"

int main()
{
	//Create static Game instance
	Game* Game = GameplayStatics::GetGame();

    TargetSpawner TargetSpawner;
	Player PlayerObj = Player();
    PlayerObj.SetSpawner(&TargetSpawner);

//
//    GameObject TestObj2 = GameObject();
//    Texture texture2 = Texture();
//    texture2.loadFromFile(ResourceManager::GetInstance()->GetAssetPathByID("Ground"));
//    TestObj2.AddComponentOfType<SpriteComponent>(texture2);
//    TestObj2.AddComponentOfType<RigidBody>();
//    TestObj2.AddComponentOfType<BoxCollider>();
//    //TestObj2.FindComponentOfType<BoxCollider>()->SetSize(150.f);
//    TestObj2.setPosition(0, 0);
//    TestObj2.setScale(1.75f, 1.75f);

//	Texture texture = Texture();
//	texture.loadFromFile(ResourceManager::GetInstance()->GetAssetPathByID("Object"));
//
//	TestObj.AddComponentOfType<SpriteComponent>(texture);
//	TestObj.FindComponentOfType<SpriteComponent>()->setScale(0.6, 0.6);
//	TestObj.AddComponentOfType<RigidBody>();
//	TestObj.FindComponentOfType<RigidBody>()->SetBodyType(b2BodyType::b2_dynamicBody);
//	TestObj.AddComponentOfType<BoxCollider>();
//    TestObj.setScale(0.5f, 0.5f);
//	if(auto Collider = TestObj.FindComponentOfType<BoxCollider>())
//	{
//		Collider->SetSize(10.f);
//		Collider->SetDensity(10.f);
//		Collider->SetFriction(100.f);
//	}



	// Run the game logic loop
	if(Game)
	{
		Game->Run();
	}
}
