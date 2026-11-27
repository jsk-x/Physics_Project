#pragma once
#include "ICameraController.h"

class CameraManager
{
private:
	ICameraController* m_currentCamera;

public:
	CameraManager();
	Camera3D getCamera();
	void update(InputController::InputsSnapshot& input, cyclone::real dt);
};

