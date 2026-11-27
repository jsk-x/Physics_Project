#include "InputController.h"
#include "raylib.h"

InputController::InputsSnapshot InputController::capture()
{
    for (int i = 0; i < (unsigned)InputKey::kCount; ++i)
        m_snapshot.data[i] = false;
    m_snapshot.mouseDelta = GetMouseDelta();

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) m_snapshot.data[(unsigned)InputKey::kRight] = true;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) m_snapshot.data[(unsigned)InputKey::kLeft] = true;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) m_snapshot.data[(unsigned)InputKey::kUp] = true;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) m_snapshot.data[(unsigned)InputKey::kDown] = true;

    if (IsMouseButtonDown(1)) m_snapshot.isMouseButtonDown = true;

    return m_snapshot;
}