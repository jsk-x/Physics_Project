#include "Launcher.h"

namespace game {

    namespace {
        constexpr float kYawRate = 30.f;
        constexpr float kPitchRate = 30.f;
        constexpr float kSpeedRate = 6.f;
    }

    Launcher::Launcher(Vector3 origin)
        : origin_(origin)
    {
    }

    void Launcher::aim(InputController::InputsSnapshot& input, float dt)
    {
        if (input.keys[0])
            launch.yaw = Clamp(launch.yaw + kYawRate * dt, kYawMin, kYawMax);
        if (input.keys[1])
            launch.yaw = Clamp(launch.yaw - kYawRate * dt, kYawMin, kYawMax);
        _pitch = Clamp(_pitch + 1 * kPitchRate * dt, kPitchMin, kPitchMax);
        _speed = Clamp(_speed + 1 * kSpeedRate * dt, kSpeedMin, kSpeedMax);

        if (input.keys[6]) _kind = ProjectileKind::Standard;
        if (input.keys[7]) _kind = ProjectileKind::Heavy;

        if (input.keys[9]) _proj.fire(shotSettings());
    }

    ShotSettings Launcher::shotSettings() const
    {
        const Matrix rotation = MatrixMultiply(
            MatrixRotateZ(_pitch * DEG2RAD),
            MatrixRotateY(-_yaw * DEG2RAD));

        const Vector3 direction = Vector3Normalize(
            Vector3Transform(Vector3{ 1.f, 0.f, 0.f }, rotation));

        return ShotSettings{ origin_, direction, _speed, _kind };
    }
}