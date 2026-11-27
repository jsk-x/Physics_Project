#pragma once
#include <optional>
#include "Projectile.h"
#include "InputController.h"
#include "ShotSettings.h"


namespace game {

    struct LauncherInput {
        float yaw = 0.f;
        float pitch = 0.f;
        float speed = 0.f;
    };

    class Launcher {
    public:
        static constexpr float kYawMin = -30.f, kYawMax = 30.f;
        static constexpr float kPitchMin = 5.f, kPitchMax = 55.f;
        static constexpr float kSpeedMin = 8.f, kSpeedMax = 22.f;

        explicit Launcher(Vector3 origin);

        void aim(InputController::InputsSnapshot& input, float dt);
        ShotSettings shotSettings() const;

    private:
        Vector3 origin_;
        float _yaw = 0.f;
        float _pitch = kPitchMin;
        float _speed = kSpeedMin;
        LauncherInput launch;
        Projectile _proj;
        ProjectileKind _kind = ProjectileKind::Standard;
    };
}