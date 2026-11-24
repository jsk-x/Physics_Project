#pragma once
#include "../Cyclone/include/cyclone/cyclone.h"
#include "InputController.h"

class ICameraController
{
public:
	 
	virtual void update(InputController::InputsSnapshot &input, cyclone::real &dt);
	virtual void getCamera();
	virtual void reset();

private:


};

