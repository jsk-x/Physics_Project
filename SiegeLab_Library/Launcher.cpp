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

    void Launcher::aim(const LauncherInput& input)
    {
        yaw_ = Clamp(yaw_ + input.yaw * kYawRate * input.dt, kYawMin, kYawMax);
        pitch_ = Clamp(pitch_ + input.pitch * kPitchRate * input.dt, kPitchMin, kPitchMax);
        speed_ = Clamp(speed_ + input.speed * kSpeedRate * input.dt, kSpeedMin, kSpeedMax);

        if (input.selectedKind) {
            kind_ = *input.selectedKind;
        }
    }

    ShotSettings Launcher::shotSettings() const
    {
        const Matrix rotation = MatrixMultiply(
            MatrixRotateZ(pitch_ * DEG2RAD),
            MatrixRotateY(-yaw_ * DEG2RAD));

        const Vector3 direction = Vector3Normalize(
            Vector3Transform(Vector3{ 1.f, 0.f, 0.f }, rotation));

        return ShotSettings{ origin_, direction, speed_, kind_ };
    }
}