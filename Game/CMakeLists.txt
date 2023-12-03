cmake_minimum_required(VERSION 3.26)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(ENGINE_ROOT X:/YNOV/ProgMoteur/Engine/Source/)

link_directories(X:/YNOV/ProgMoteur/Engine/cmake-build-debug/)
add_executable(Game main.cpp
        Source/GameObjects/Private/Player.cpp
        Source/GameObjects/Public/Player.h
        Source/Components/Private/CarCollision.cpp
        Source/Components/Public/CarCollision.h
        Source/GameObjects/Private/TargetSpawner.cpp
        Source/GameObjects/Public/TargetSpawner.h
        Source/GameObjects/Private/Target.cpp
        Source/GameObjects/Public/Target.h
)

file(GLOB_RECURSE HEADER_DIRS LIST_DIRECTORIES true "${ENGINE_ROOT}*.h")
foreach(HEADER_DIR ${HEADER_DIRS})
    get_filename_component(DIR ${HEADER_DIR} DIRECTORY)
    target_include_directories(Game PRIVATE ${DIR})
endforeach()

# SFML
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_include_directories(Game PRIVATE ${SFML_INCLUDE_DIR})

# Boost
set(Boost_NO_WARN_NEW_VERSIONS ON)
find_package(Boost COMPONENTS system filesystem REQUIRED)

# yaml-cpp
find_package(yaml-cpp CONFIG REQUIRED)
target_include_directories(Game PRIVATE ${YAML_CPP_INCLUDE_DIR})

# box2d
find_package(box2d CONFIG REQUIRED)
target_include_directories(Game PRIVATE ${BOX2D_INCLUDE_DIR})

target_link_libraries(Game PRIVATE Engine sfml-graphics sfml-window sfml-system sfml-audio yaml-cpp::yaml-cpp Boost::filesystem box2d::box2d)
