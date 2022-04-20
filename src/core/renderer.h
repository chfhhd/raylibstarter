#pragma once

#include <raylib.h>
#include <memory>
#include "scene.h"
#include "sprite.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

namespace game::core {
    class Renderer final {
    public:
        // Clamp Vector2 value with MIN and MAX and return a new vector2
        // NOTE: Required for virtual mouse, to clamp inside virtual game size
        [[nodiscard]] static Vector2 ClampValue(Vector2 value, Vector2 MIN, Vector2 MAX);

        static void UpdateMousePosition(int stage_width, int stage_height);

        static void DrawRenderTexture(RenderTexture2D target, int stage_width, int stage_height);

        static void DrawTexture(const std::shared_ptr<game::core::Sprite>& sprite);
    };
}
