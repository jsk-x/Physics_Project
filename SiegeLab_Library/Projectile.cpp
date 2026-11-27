#include "Projectile.h"
#include "InputController.h"

Projectile::Projectile()
{
}

void Projectile::fire(cyclone::Contact settings)
{
	
}

void Projectile::draw()
{
	cyclone::Vector3 cyclonePosition = m_body.getPosition();
	Vector3 position(cyclonePosition.x,cyclonePosition.y,cyclonePosition.z);

	DrawSphere(position, m_sphere.radius, color);
}

void Projectile::registerPhysics(cyclone::World world)
{
	
}
