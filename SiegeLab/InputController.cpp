#include "InputController.h"
#include "raylib.h"

void InputController::capture()
{
    for (int i = 0; i < (unsigned)InputKey::kCount; ++i)
        m_snapshot.data[i] = false;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) m_snapshot.data[(unsigned)InputKey::kRight] = true;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) m_snapshot.data[(unsigned)InputKey::kLeft] = true;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) m_snapshot.data[(unsigned)InputKey::kUp] = true;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) m_snapshot.data[(unsigned)InputKey::kDown] = true;
}
