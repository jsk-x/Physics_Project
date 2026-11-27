#pragma once
#include "ICameraController.h"
#include "raylib.h"

class OrbitCamera : public ICameraController
{

public:
	struct Objects
	{
		cyclone::real rotationSpeed = 0.25;
		cyclone::real yaw = 45;
		cyclone::real pitch = 45;
		cyclone::real dist;

		void clear()
		{
			rotationSpeed = -1;
			yaw = 0;
			pitch = 0;
		}
	};

	Objects camObjects;
	Vector3 m_position = { 10.f, 10.f, 10.f };
	Vector3 m_target = { 0.0f, 0.0f, 0.0f };

	//FRIEND_TEST(GP_T3, C01);

public:

	void update(InputController::InputsSnapshot &input, cyclone::real &dt) override;

	// Hérité via ICameraController
	Camera3D getCamera() override;
	void reset() override;
};

