#include "CameraManager.h"
#include "OrbitCamera.h"
#include "raylib.h"

CameraManager::CameraManager()
{
	m_currentCamera = new OrbitCamera();
}

Camera3D CameraManager::getCamera()
{
	return m_currentCamera->getCamera();
}

void CameraManager::update(InputController::InputsSnapshot& input, cyclone::real dt)
{
	return m_currentCamera->update(input, dt);
}
