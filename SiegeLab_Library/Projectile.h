#pragma once
#include "GameEntity.h"
#include <cyclone/collide_fine.h>
#include "raylib.h"

class Projectile : public GameEntity
{
public:
	
	Projectile();
	void fire(cyclone::Contact settings);
	void draw() override;
	void registerPhysics(cyclone::World world) override;

protected:

	cyclone::CollisionSphere m_sphere;

	Color color;
};

