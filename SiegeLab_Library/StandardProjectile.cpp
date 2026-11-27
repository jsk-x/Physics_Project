#include "StandardProjectile.h"

StandardProjectile::StandardProjectile()
{
	
}

void StandardProjectile::configurePhysics()
{
	m_body.setMass(1);
	m_sphere.radius = 0.28;
}
