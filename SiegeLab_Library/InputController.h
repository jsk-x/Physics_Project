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
		kSpeedDown = 4,
		kSpeedUp = 5,
		kSelectStandard = 6,
		kSelectHeavy = 7,
		kReset = 8,
		kSpace = 9,
		kCount
	};
	struct InputsSnapshot
	{
		bool keys[(unsigned)InputKey::kCount];
		bool isMouseButtonDown;
		Vector2 mouseDelta;
	};

	InputsSnapshot capture();

private:
	InputsSnapshot m_snapshot;
};

