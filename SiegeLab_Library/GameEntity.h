#pragma once
#include <cyclone/world.h>

class GameEntity {
public:
    virtual ~GameEntity() = default;

    virtual void draw() = 0;

    virtual void registerPhysics(cyclone::World world) = 0;

    virtual void unregisterColliders() {}

protected:

    cyclone::RigidBody m_body;
};
