#pragma once
#include "raylib.h"

class InputController
{
public:
	enum class InputKey {
		kRight = 0,
		kLeft = 1,
		kUp = 2,
		kDown = 3,
		kReset = 4,
		kCount
	};
	struct InputsSnapshot
	{
		bool data[(unsigned)InputKey::kCount];
		bool isMouseButtonDown;
		Vector2 mouseDelta;
	};

	InputsSnapshot capture();

private:
	InputsSnapshot m_snapshot;
};

