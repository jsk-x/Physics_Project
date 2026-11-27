#pragma once
#include "raylib.h"
#include "raymath.h"

namespace game {

    enum class ProjectileKind { Standard, Heavy };

    struct ShotSettings {
        Vector3 origin{ 0.f, 0.f, 0.f };
        Vector3 direction{ 1.f, 0.f, 0.f };
        float speed = 0.f;
        ProjectileKind projectileKind = ProjectileKind::Standard;

        Vector3 initialVelocity() const { return Vector3Scale(direction, speed); }
    };

}