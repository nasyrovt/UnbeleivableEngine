//
// Created by Nasyrov Takhir on 30/10/2023.
//

#ifndef CUSTOMENGINE_OBJECT_H
#define CUSTOMENGINE_OBJECT_H

#include <SFML/Graphics.hpp>

using namespace std;

class Object
{

public:
    Object();

    [[nodiscard]] int GetUniqueId() const;

    [[nodiscard]] bool IsActive() const { return bIsActive; }

    virtual void Activate();
    virtual void Deactivate();
    virtual void Initialize();
    virtual void Destroy();
    virtual void RegisterToStore();
    virtual void UnregisterFromStore();

private:
    int uniqueId;
    string objectName;
    bool bIsActive;

    static int uniqueIdCounter;
};

#endif //CUSTOMENGINE_OBJECT_H
