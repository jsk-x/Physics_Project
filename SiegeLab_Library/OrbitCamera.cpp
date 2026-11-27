#include "OrbitCamera.h"
#include "raymath.h"
#include <iostream>

void OrbitCamera::update(InputController::InputsSnapshot& input, cyclone::real& dt)
{
	/*if (input.data[(unsigned)InputController::InputKey::kRight]) m_position.x += 0.5;
	if (input.data[(unsigned)InputController::InputKey::kLeft]) m_position.x -= 0.5;
	if (input.data[(unsigned)InputController::InputKey::kUp]) m_position.y -= 0.5;
	if (input.data[(unsigned)InputController::InputKey::kDown]) m_position.y += 0.5;*/

	if (input.data[(unsigned)InputController::InputKey::kReset]) reset();

	if (input.isMouseButtonDown)
	{
		camObjects.yaw += input.mouseDelta.x * camObjects.rotationSpeed;
		camObjects.pitch += input.mouseDelta.y * camObjects.rotationSpeed;

		//std::cout << camObjects.yaw << ", " << camObjects.pitch << std::endl;

		if (camObjects.pitch > 90) camObjects.pitch = 90;
		if (camObjects.pitch < 0) camObjects.pitch = 0;
	}

	camObjects.dist -= GetMouseWheelMove();
	if (camObjects.dist < 1) camObjects.dist = 1;
	if (camObjects.dist > 10) camObjects.dist = 10;

	Vector3 pos = { 0, 0, camObjects.dist };

	Matrix pitchMat = MatrixRotateX(camObjects.pitch * dt);
	Matrix yawMat = MatrixRotateY(camObjects.yaw * dt);
	Matrix mat = MatrixMultiply(pitchMat, yawMat);

	pos = Vector3Transform(pos, mat);
	m_position = pos;
}

Camera3D OrbitCamera::getCamera()
{
	Camera3D cam = { 0 };
	cam.position = m_position; // Camera position
	cam.target = m_target;      // Camera looking at point
	cam.up = { 0.0f, -1.0f, 0.0f };          // Camera up vector (rotation towards target)
	cam.fovy = 45.0f;                                // Camera field-of-view Y
	cam.projection = CAMERA_PERSPECTIVE;
	return cam;
}

void OrbitCamera::reset()
{
	camObjects.rotationSpeed = 1;
	m_target = { 0.0f, 0.0f, 0.0f };
	camObjects.yaw = 0;
	camObjects.pitch = 0;
}
