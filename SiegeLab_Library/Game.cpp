#include "pch.h"
#include "framework.h"

#include "Game.h"
#include "CameraManager.h"
#include "ObjPool.h"
#include "GameEntity.h"
#include "StandardProjectile.h"
#include "HeavyProjectile.h"

#include "raylib.h"

void Game::Run()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	const int height = 800;
	const int width = 600;

	game::ObjectPool<GameEntity, 2> pool;
	pool.create<StandardProjectile>();
	pool.create<HeavyProjectile>();
	// Create the window and OpenGL context
	InitWindow(height, width, "Hello Raylib");
	CameraManager cams;

	InputController inputs;

	Vector3 cube = { 0.0f, -1.0f, 0.0f };

	DisableCursor();

	SetTargetFPS(60);

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{		
		InputController::InputsSnapshot snap = inputs.capture();
		cams.update(snap, GetFrameTime());

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(WHITE);

		BeginMode3D(cams.getCamera());

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, BLACK);
		DrawCube(cube, 2.0f, 2.0f, 2.0f, BLUE);
		pool.forEach([](GameEntity* obj) {obj->draw();});

		DrawCubeWires(cube, 2.0f, 2.0f, 2.0f, SKYBLUE);

		//draw on GameEntity

		DrawGrid(10, 1.0f);

		EndMode3D();

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
}
