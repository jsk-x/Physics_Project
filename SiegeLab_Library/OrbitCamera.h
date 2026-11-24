#pragma once
#include "ICameraController.h"

struct Objects
{
	cyclone::real rotationSpeed;
	Vector3 target;
	cyclone::real yaw;
	cyclone::real pitch;

	void clear()
	{
		rotationSpeed = -1;
		target = { 0.0, 0.0, 0.0 };
		yaw = 0;
		pitch = 0;
	}
};

class OrbitCamera : public ICameraController
{
private:

	Objects* camObjects;

public:

	void update(InputController::InputsSnapshot &input, cyclone::real &dt) override;

	// Hérité via ICameraController
	Camera3D getCamera() override;
	void reset() override;
};

