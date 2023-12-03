//
// Created by Nasyrov Takhir on 02/11/2023.
//

#ifndef CUSTOMENGINE_BOXCOLLIDER_H
#define CUSTOMENGINE_BOXCOLLIDER_H

#include <box2d/b2_polygon_shape.h>
#include "Collider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider();

	void SetSize(float InSize);
	void OnCollisionEnter(Collision *InCollision) override;
	void OnCollisionExit(Collision *InCollision) override;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
protected:
	float Size;
	b2PolygonShape CollisionShape;
	b2Shape* GetCollisionShape() override;

};


#endif //CUSTOMENGINE_BOXCOLLIDER_H
