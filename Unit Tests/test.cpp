#include "pch.h"
#include <Game.h>
#include <ObjPool.h>

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
}

