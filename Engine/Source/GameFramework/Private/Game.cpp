//
// Created by Nasyrov Takhir on 30/10/2023.
//

#include "../Public/Game.h"
#include "../../Object/Public/Object.h"
#include "../../Object/Public/GameObject/GameObject.h"
#include "../Public/GameplayStatics.h"
#include "../Public/ResourceManager.h"
#include "../Public/Physics/Physics.h"


Game::Game()  : isRunning(false)
{
    Window.create(sf::VideoMode(WindowWidth, WindowHeight), "Unbelievable Engine");
	ResourceManager::GetInstance()->FetchConfigFiles();
    ObjectStore = GameplayStatics::GetObjectStore();
	Physics = GameplayStatics::GetPhysics();
}

void Game::Run()
{
    InitializeObjects();

	isRunning = true;
	BeginPlay();

    sf::Clock clock;
    sf::Time deltaTime;

    while (isRunning) {
        sf::Event event;
        while (Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isRunning = false;
            }
        }

        deltaTime = clock.restart();
        DeltaTime = deltaTime.asSeconds();
        //TODO: Update game logic (e.g., handle input, update game Objects, etc.).
        HandleInput(event);
        TickGameObjects(DeltaTime);

        Window.clear();

        DrawGameObjects();
        LateTickGameObjects(DeltaTime);

		GameplayStatics::GetPhysicsWorld()->DebugDraw();
        Window.display();
    }
    EndPlay();
}

void Game::HandleInput(Event event)
{
    auto GameObjects = ObjectStore->GetGameObjects();
    for(const auto& GameObject : GameObjects)
    {
        if(GameObject.second != nullptr && GameObject.second->IsActive())
            GameObject.second->HandleInput(event);
    }
}

void Game::TickGameObjects(float InDeltaTime)
{
    auto GameObjects = ObjectStore->GetGameObjects();
    for(const auto& GameObject : GameObjects)
    {
        GameObject.second->Tick(InDeltaTime);
    }
}

void Game::DrawGameObjects()
{
    auto GameObjects = ObjectStore->GetGameObjects();
    for(const auto& GameObject : GameObjects)
    {
        sf::RenderStates states;
        GameObject.second->draw(Window, states);
    }
}

void Game::BeginPlay()
{
    auto GameObjects = ObjectStore->GetGameObjects();
    for(const auto& GameObject : GameObjects)
    {
        GameObject.second->BeginPlay();
    }
}

void Game::EndPlay()
{
    auto GameObjects = ObjectStore->GetGameObjects();
    for(const auto& GameObject : GameObjects)
    {
        GameObject.second->EndPlay();
    }
}

Game* Game::GetGame()
{
    static Game GameInstance;
    return &GameInstance;
}

void Game::SetWindowView(sf::View* InView)
{
    Window.setView(*InView);
}

void Game::LateTickGameObjects(float InDeltaTime)
{
    auto GameObjects = ObjectStore->GetGameObjects();
	for(const auto& GameObject : GameObjects)
    {
	    GameObject.second->LateTick(InDeltaTime);
    }
	Physics->LateTick(InDeltaTime);
}

sf::View Game::GetDefaultView()
{
    return Window.getDefaultView();
}

void Game::InitializeObjects()
{
    auto GameObjects = ObjectStore->GetGameObjects();
    for(const auto& GameObject : GameObjects)
    {
        GameObject.second->Initialize();
    }
}

