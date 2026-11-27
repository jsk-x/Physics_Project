#include <Game.h>

#include "raylib.h"
#include "raymath.h"
int main()
{
	Game game;
	game.Run();
	/*return 0;*/

    /*// Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [camera] example - third person orbit camera");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    Image img = GenImageChecked(256, 256, 64, 64, LIGHTGRAY, WHITE);
    Texture tx = LoadTextureFromImage(img);

    // setup initial camera data
    Camera3D orbitCam;

    orbitCam.fovy = 45;
    orbitCam.target = Vector3{ 1, 0 ,0 };
    orbitCam.position = Vector3{ 0,0,5 };
    orbitCam.up = Vector3{ 0, 1, 0 };
    orbitCam.projection = CAMERA_PERSPECTIVE;

    float camDist = 5;  // how far away from the target the camera is (radius)
    float rotAngle = 45; // the rotation angle around the target  (around Y)
    float tiltAngle = 45; // the tilt tangle of the camera (up/down)

    float rotSpeed = 0.25f; // to scale the mouse input
    float moveSpeed = 3.0f; // to scale the linear input

    Vector2 cursorPos = GetMousePosition(); // save off current position so we have a start point

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsMouseButtonDown(1)) // only rotate on right click
        {
            Vector2 newPos = GetMousePosition();

            // update the angles from the delta
            rotAngle += (newPos.x - cursorPos.x) * rotSpeed;
            tiltAngle += (newPos.y - cursorPos.y) * rotSpeed;

            // clamp the tilt so we don't get gymbal lock
            if (tiltAngle > 89)
                tiltAngle = 89;
            if (tiltAngle < 1)
                tiltAngle = 1;
        }
        // always update the position so we don't get jumps
        cursorPos = GetMousePosition();

        // vector in rotation space to move
        Vector3 moveVec = { 0,0,0 };

        if (IsKeyDown(KEY_W))
            moveVec.z = -moveSpeed * GetFrameTime();
        if (IsKeyDown(KEY_S))
            moveVec.z = moveSpeed * GetFrameTime();

        if (IsKeyDown(KEY_A))
            moveVec.x = -moveSpeed * GetFrameTime();
        if (IsKeyDown(KEY_D))
            moveVec.x = moveSpeed * GetFrameTime();

        // update zoom
        camDist -= GetMouseWheelMove();
        if (camDist < 1)
            camDist = 1;
        if (camDist > 10)
            camDist = 10;

        // vector we are going to transform to get the camera offset from the target point
        Vector3 camPos = { 0, 0, camDist };

        Matrix tiltMat = MatrixRotateX(tiltAngle * GetFrameTime()); // a matrix for the tilt rotation
        Matrix rotMat = MatrixRotateY(rotAngle * GetFrameTime()); // a matrix for the plane rotation
        Matrix mat = MatrixMultiply(tiltMat, rotMat); // the combined transformation matrix for the camera position

        camPos = Vector3Transform(camPos, mat); // transform the camera position into a vector in world space
        moveVec = Vector3Transform(moveVec, rotMat); // transform the movement vector into world space, but ignore the tilt so it is in plane

        orbitCam.target = Vector3Add(orbitCam.target, moveVec); // move the target to the moved position

        orbitCam.position = Vector3Add(orbitCam.target, camPos); // offset the camera position by the vector from the target position

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(orbitCam);
        DrawPlane(Vector3{ 0,0,0 }, Vector2{ 50,50 }, BLUE); // simple world plane

        // grid of cubes to make a "world"
        float spacing = 3;
        int count = 5;

        for (float x = -count * spacing; x <= count * spacing; x += spacing)
        {
            for (float z = -count * spacing; z <= count * spacing; z += spacing)
            {
                DrawCube(Vector3{ x, 0.5f, z }, 1, 1, 1, WHITE);
            }
        }

        // target point
        DrawSphere(orbitCam.target, 0.25f, RED);

        EndMode3D();

        // instructions
        DrawText("Right drag to rotate, Wheel to zoom, WASD to move", 100, 760, 20, GREEN);
        DrawFPS(0, 0);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------*/

    return 0;
}