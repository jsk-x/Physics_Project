#pragma once
#include "ICameraController.h"

struct Objects
{
	cyclone::real rotationSpeed;
	cyclone::real target;
	cyclone::real yaw;
	cyclone::real pitch;
};

class OrbitCamera : public ICameraController
{
private:

	Objects* camObjects;

public:

	void update(InputController::InputsSnapshot &input, cyclone::real &dt) override;
};

