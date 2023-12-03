//
// Created by Nasyrov Takhir on 01/11/2023.
//

#ifndef CUSTOMENGINE_GAMEPLAYSTATICS_H
#define CUSTOMENGINE_GAMEPLAYSTATICS_H


class GameplayStatics
{
public:
    static class Game* GetGame();

    static class ObjectStore* GetObjectStore();

	static class b2World* GetPhysicsWorld();

	static class Physics* GetPhysics();

};


#endif //CUSTOMENGINE_GAMEPLAYSTATICS_H
