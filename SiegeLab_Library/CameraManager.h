#pragma once
#include "InputController.h"
#include "ICameraController.h"

class CameraManager
{
private:
	ICameraController* currentCamera;

public:
	Camera3D getCamera();
	void setActive();
};

