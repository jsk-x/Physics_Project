#pragma once
#include <optional>
#include "ShotSettings.h"

namespace game {

    struct LauncherInput {
        float yaw = 0.f;
        float pitch = 0.f;
        float speed = 0.f;
        std::optional<ProjectileKind> selectedKind;
        float dt = 0.f;
    };

    class Launcher {
    public:
        static constexpr float kYawMin = -30.f, kYawMax = 30.f;
        static constexpr float kPitchMin = 5.f, kPitchMax = 55.f;
        static constexpr float kSpeedMin = 8.f, kSpeedMax = 22.f;

        explicit Launcher(Vector3 origin);

        void aim(const LauncherInput& input);
        ShotSettings shotSettings() const;

    private:
        Vector3 origin_;
        float yaw_ = 0.f;
        float pitch_ = kPitchMin;
        float speed_ = kSpeedMin;
        ProjectileKind kind_ = ProjectileKind::Standard;
    };
}