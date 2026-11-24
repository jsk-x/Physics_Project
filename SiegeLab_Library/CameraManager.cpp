#include "CameraManager.h"
#include "raylib.h"

Camera3D CameraManager::getCamera()
{
	return currentCamera->getCamera();
}

void CameraManager::setActive()
{
}
