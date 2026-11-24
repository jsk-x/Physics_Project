#include "pch.h"
#include "framework.h"

#include "Game.h"
#include "CameraManager.h"

#include "raylib.h"

void Game::Run()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(800, 600, "Hello Raylib");
	CameraManager cams;

	SetTargetFPS(60);

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		BeginMode3D(cams.getCamera());

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);
		DrawTriangle3D(Vector3{ 400, 300, 100 }, Vector3{ 350, 100, 100 }, Vector3{ 300, 300, 100 }, YELLOW);

		EndMode3D();

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
}
