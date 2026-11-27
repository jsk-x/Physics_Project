#pragma once
#include "raylib.h"

class InputController
{
public:
	enum class InputKey {
		kRight = 0,
		kLeft,
		kUp,
		kDown,
		kSpeedDown,
		kSpeedUp,
		kSelectStandard,
		kSelectHeavy,
		kReset,
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
