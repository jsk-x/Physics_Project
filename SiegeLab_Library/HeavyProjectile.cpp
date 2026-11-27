#include "HeavyProjectile.h"

HeavyProjectile::HeavyProjectile()
{
	color = BLACK;
}

void HeavyProjectile::configurePhysics()
{
	m_body.setMass(2);
	m_sphere.radius = 0.36;
}
