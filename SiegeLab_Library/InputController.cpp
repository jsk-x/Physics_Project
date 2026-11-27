#include "InputController.h"
#include "raylib.h"

InputController::InputsSnapshot InputController::capture()
{
    for (int i = 0; i < (unsigned)InputKey::kCount; ++i)
        m_snapshot.keys[i] = false;
    m_snapshot.mouseDelta = GetMouseDelta();

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) m_snapshot.keys[(unsigned)InputKey::kRight] = true;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) m_snapshot.keys[(unsigned)InputKey::kLeft] = true;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) m_snapshot.keys[(unsigned)InputKey::kUp] = true;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) m_snapshot.keys[(unsigned)InputKey::kDown] = true;
    if (IsKeyDown(KEY_SPACE)) m_snapshot.keys[(unsigned)InputKey::kSpace] = true;

    if (IsKeyDown(KEY_Q)) m_snapshot.keys[(unsigned)InputKey::kSpeedDown] = true;
    if (IsKeyDown(KEY_E)) m_snapshot.keys[(unsigned)InputKey::kSpeedUp] = true;

    if (IsKeyPressed(KEY_ONE)) m_snapshot.keys[(unsigned)InputKey::kSelectStandard] = true;
    if (IsKeyPressed(KEY_TWO)) m_snapshot.keys[(unsigned)InputKey::kSelectHeavy] = true;

    if (IsKeyPressed(KEY_R)) m_snapshot.keys[(unsigned)InputKey::kReset] = true;

    if (IsMouseButtonDown(1)) m_snapshot.isMouseButtonDown = true;

    return m_snapshot;
}
