//
// Created by Nasyrov Takhir on 30/10/2023.
//

#ifndef CUSTOMENGINE_GAMEOBJECT_H
#define CUSTOMENGINE_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>

#include "../Object.h"
#include "../ITickable.h"
#include "../../../Component/Public/Base/BaseComponent.h"


using namespace std;
using namespace sf;

class GameObject : public Object, public ITickable, public Transformable, public Drawable {

public:
    GameObject();

    virtual void BeginPlay();
    virtual void EndPlay();

    template<typename T, typename... Args>
    void AddComponentOfType(Args&&... args)
    {
        static_assert(std::is_base_of<BaseComponent, T>::value, "T must be a subclass of BaseComponent");
        auto Component = make_shared<T>(std::forward<Args>(args)...);
        auto ComponentCasted = std::dynamic_pointer_cast<BaseComponent>(Component);
	    ComponentCasted->SetOwner(this);
		//ComponentCasted->InitializeComponent();
	    Components.push_back(ComponentCasted);
    }

    template<typename T>
    std::shared_ptr<T> FindComponentOfType()
    {
        static_assert(std::is_base_of<BaseComponent, T>::value, "T must be a subclass of BaseComponent");
        for(const auto& Component : Components)
        {
            std::shared_ptr<T> CastedComponent = std::dynamic_pointer_cast<T>(Component);
            if(CastedComponent)
                return CastedComponent;
        }
        return nullptr;
    }

	template<typename T>
	vector<std::shared_ptr<T>> FindComponentsOfType()
	{
		vector<std::shared_ptr<T>> result;
		static_assert(std::is_base_of<BaseComponent, T>::value, "T must be a subclass of BaseComponent");
		for(const auto& Component : Components)
		{
			std::shared_ptr<T> CastedComponent = std::dynamic_pointer_cast<T>(Component);
			if(CastedComponent)
			{
				result.push_back(CastedComponent);
			}
		}
		return result;
	}

    void Tick(float DeltaTime) override;

    void LateTick(float DeltaTime) override;
    void Activate() override;
    virtual void HandleInput(sf::Event InEvent);

    void Deactivate() override;
    void RegisterToStore() override;
    void UnregisterFromStore() override;
    void Initialize() override;
    void Destroy() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

protected:
    vector<shared_ptr<BaseComponent>> Components;
};


#endif //CUSTOMENGINE_GAMEOBJECT_H
