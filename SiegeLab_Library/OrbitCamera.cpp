#include "OrbitCamera.h"

void OrbitCamera::update(InputController::InputsSnapshot& input, cyclone::real& dt)
{
}

Camera3D OrbitCamera::getCamera()
{
	Camera3D cam = { 0 };
	cam.position = { 10.0f, 10.0f, 10.0f }; // Camera position
	cam.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
	cam.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	cam.fovy = 45.0f;                                // Camera field-of-view Y
	cam.projection = CAMERA_PERSPECTIVE;
	return cam;
}

void OrbitCamera::reset()
{
	camObjects->rotationSpeed = 1;
	camObjects->target = { 0.0f };
	camObjects->yaw = 0;
	camObjects->pitch = 0;
}
