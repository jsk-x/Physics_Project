#pragma once
#include <cyclone/cyclone.h>
#include "InputController.h"
#include "raylib.h"

class ICameraController
{
public:
	 
	virtual void update(InputController::InputsSnapshot &input, cyclone::real &dt) = 0;
	virtual Camera3D getCamera() = 0;
	virtual void reset() = 0;

};

