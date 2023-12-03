cmake_minimum_required(VERSION 3.26)
project(Engine)

set(CMAKE_CXX_STANDARD 20)
set(Boost_NO_WARN_NEW_VERSIONS ON)
set(GAME_PATH X:/YNOV/ProgMoteur/Game/cmake-build-debug/)

add_library(Engine STATIC
        Source/Object/Private/Object.cpp
        Source/Object/Public/Object.h
        Source/Object/Private/ObjectStore.cpp
        Source/Object/Public/ObjectStore.h
        Source/GameFramework/Private/Game.cpp
        Source/GameFramework/Public/Game.h
        Source/Object/Public/ITickable.h
        Source/Component/Private/Base/BaseComponent.cpp
        Source/Component/Public/Base/BaseComponent.h
        Source/Object/Private/GameObject/GameObject.cpp
        Source/Object/Public/GameObject/GameObject.h
        Source/Component/Private/Base/SceneComponent.cpp
        Source/Component/Public/Base/SceneComponent.h
        Source/Component/Private/Base/ActorComponent.cpp
        Source/Component/Public/Base/ActorComponent.h
        Source/Component/Private/Drawable/SpriteComponent.cpp
        Source/Component/Public/Drawable/SpriteComponent.h
        Source/Component/Private/Camera/CameraComponent.cpp
        Source/Component/Public/Camera/CameraComponent.h
        Source/GameFramework/Private/GameplayStatics.cpp
        Source/GameFramework/Public/GameplayStatics.h
        Source/GameFramework/Private/ResourceManager.cpp
        Source/GameFramework/Public/ResourceManager.h
        Source/Component/Private/Collision/RigidBody.cpp
        Source/Component/Public/Collision/RigidBody.h
        Source/GameFramework/Private/Physics/Physics.cpp
        Source/GameFramework/Public/Physics/Physics.h
        Source/Component/Private/Collision/Collider.cpp
        Source/Component/Public/Collision/Collider.h
        Source/Component/Private/Collision/BoxCollider.cpp
        Source/Component/Public/Collision/BoxCollider.h
        Source/GameFramework/Public/Physics/ICollidable.h
        Source/GameFramework/Private/Physics/Collision.cpp
        Source/GameFramework/Public/Physics/Collision.h
        Source/GameFramework/Private/Physics/CollisionListener.cpp
        Source/GameFramework/Public/Physics/CollisionListener.h
        Source/Debug/Private/DrawHelper.cpp
        Source/Debug/Public/DrawHelper.h
        Source/Component/Private/Scripting/LuaScript.cpp
        Source/Component/Public/Scripting/LuaScript.h
)

find_package(box2d CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED )
find_package(yaml-cpp CONFIG REQUIRED)

include_directories(${SFML_INCLUDE_DIRS})
target_include_directories(Engine PRIVATE ${YAML_CPP_INCLUDE_DIR})
target_link_libraries(Engine sfml-system sfml-window sfml-graphics sfml-audio sfml-network box2d::box2d yaml-cpp::yaml-cpp Boost::filesystem)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY Config DESTINATION ${CMAKE_BINARY_DIR})
file(COPY Log DESTINATION ${CMAKE_BINARY_DIR})
