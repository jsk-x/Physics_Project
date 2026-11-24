#pragma once

class InputController
{
public:
	enum class InputKey {
		kRight = 0,
		kLeft = 1,
		kUp = 2,
		kDown = 3,
		kCount
	};
	struct InputsSnapshot
	{
		bool data[(unsigned)InputKey::kCount];
	};
public:

	void capture();

private:
	InputsSnapshot m_snapshot;

	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();
};

