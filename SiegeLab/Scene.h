#pragma once

template <typename T, typename Capacity> class ObjectPool {
	create();
	getId();
	destroy();
	clear();
};

template <typename T> class createEntity {

};

struct SceneObjects{
	void createEntity();
	void getId();
	void flushRemovals();
};

class EntityId {
	int slot;
	int generation;
};

class GameEntity {
	virtual void draw() = 0;
};