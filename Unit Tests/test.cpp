#include "pch.h"
#include <Game.h>
#include <ObjPool.h>
#include <OrbitCamera.h>
#include <InputController.h>

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
		snapshot.data[i] = false;

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