#include "pch.h"
#include <Game.h>
#include <ObjPool.h>
#include <OrbitCamera.h>
#include <InputController.h>
#include <Launcher.h>

TEST(TestCaseName, TestName) {

	Game game;

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

namespace {
	struct Object {
		int value = 0;
		Object() = default;
		Object(int v) : value(v) {}
	};

	using Pool = game::ObjectPool<Object, 3>;
}

TEST(ObjectPoolTest, Test_1) {
	Pool pool;
	game::EntityId id = pool.create(Object{ 42 });

	EXPECT_EQ(pool.get(id)->value, 42);


  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(GP_T3, C01) {

	InputController::InputsSnapshot snapshot;
	for (int i = 0; i < (unsigned)InputController::InputKey::kCount; ++i)
		snapshot.keys[i] = false;

	OrbitCamera cams;

	cams.m_target = {2, 1, 0};
	cams.camObjects.dist = 10;
	cams.camObjects.yaw = 0;
	cams.camObjects.pitch = 20;

	OrbitCamera cams2;

	cams2.m_target = { 2, 1, 0 };
	cams2.camObjects.dist = 10;
	cams2.camObjects.yaw = 0;
	cams2.camObjects.pitch = 20;

	cyclone::real dt = 1;
	cams.update(snapshot, dt);
	cams2.update(snapshot, dt);


	EXPECT_NEAR(cams.m_position.x, 2, 0.0001);
	EXPECT_NEAR(cams.m_position.y, 4.4202, 0.0001);
	EXPECT_NEAR(cams.m_position.z, 9.3969, 0.0001);


}
namespace {

    void aimFor(game::Launcher& launcher, float yaw, float pitch, float speed, float seconds) {
        game::LauncherInput in;
        in.yaw = yaw;
        in.pitch = pitch;
        in.speed = speed;
        float dt = seconds;
        launcher.aim(&in, dt);
    }

    game::Launcher makeLauncher() {
        return game::Launcher(Vector3{ 0.f, 0.f, 0.f });
    }

}

TEST(LauncherTest, DirectionPositive) {
    game::Launcher launcher = makeLauncher();
    Vector3 d = launcher.shotSettings().direction;

    EXPECT_GT(d.x, 0.f);
    EXPECT_NEAR(d.z, 0.f, 1e-5f);
}

TEST(LauncherTest, YawLimit) {
    game::Launcher launcher = makeLauncher();

    aimFor(launcher, 1.f, 0.f, 0.f, 10.f);
    Vector3 d = launcher.shotSettings().direction;
    EXPECT_NEAR(d.z / d.x, std::tan(game::Launcher::kYawMax * DEG2RAD), 1e-4f);

    aimFor(launcher, -1.f, 0.f, 0.f, 20.f);
    d = launcher.shotSettings().direction;
    EXPECT_NEAR(d.z / d.x, std::tan(game::Launcher::kYawMin * DEG2RAD), 1e-4f);
}

TEST(LauncherTest, PitchLimit) {
    game::Launcher launcher = makeLauncher();

    aimFor(launcher, 0.f, 1.f, 0.f, 10.f);
    EXPECT_NEAR(launcher.shotSettings().direction.y,
        std::sin(game::Launcher::kPitchMax * DEG2RAD), 1e-4f);

    aimFor(launcher, 0.f, -1.f, 0.f, 20.f);
    EXPECT_NEAR(launcher.shotSettings().direction.y,
        std::sin(game::Launcher::kPitchMin * DEG2RAD), 1e-4f);
}

TEST(LauncherTest, SpeedLimit) {
    game::Launcher launcher = makeLauncher();

    aimFor(launcher, 0.f, 0.f, 1.f, 10.f);
    EXPECT_FLOAT_EQ(launcher.shotSettings().speed, game::Launcher::kSpeedMax);

    aimFor(launcher, 0.f, 0.f, -1.f, 10.f);
    EXPECT_FLOAT_EQ(launcher.shotSettings().speed, game::Launcher::kSpeedMin);
}

TEST(LauncherTest, InitialVelocity) {
    game::Launcher launcher = makeLauncher();
    aimFor(launcher, 1.f, 1.f, 1.f, 0.4f);

    game::ShotSettings s = launcher.shotSettings();
    Vector3 v = s.initialVelocity();

    EXPECT_NEAR(v.x, s.direction.x * s.speed, 1e-5f);
    EXPECT_NEAR(v.y, s.direction.y * s.speed, 1e-5f);
    EXPECT_NEAR(v.z, s.direction.z * s.speed, 1e-5f);
}

