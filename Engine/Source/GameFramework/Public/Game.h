//
// Created by Nasyrov Takhir on 30/10/2023.
//
#pragma once

#ifndef CUSTOMENGINE_GAME_H
#define CUSTOMENGINE_GAME_H

#include <iostream>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "../../Object/Public/ObjectStore.h"

using namespace sf;


class Game
{
    friend class GameplayStatics;

public:
    void Run();
    void SetWindowView(View* InView);
    View GetDefaultView();
    float GetDeltaSeconds() const { return DeltaTime; }
    bool IsRunning() const { return isRunning; }

    int WindowWidth = 1920;
    int WindowHeight = 1080;

protected:
    static Game* GetGame();

private:
    Game();

    bool isRunning;
    ObjectStore* ObjectStore;
    RenderWindow Window;
	class Physics* Physics;
    float DeltaTime;

    void HandleInput(Event event);
    void TickGameObjects(float InDeltaTime);

    void DrawGameObjects();

    virtual void BeginPlay();

    void EndPlay();

    void LateTickGameObjects(float InDeltaTime);

    void InitializeObjects();

};


#endif //CUSTOMENGINE_GAME_H
