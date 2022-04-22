#pragma once

#include <raylib.h>
#include "scene.h"
#include "sprite.h"

namespace game::core {
    class Renderer final {
    public:
        static void DrawTexture(const std::shared_ptr<game::core::Sprite>& sprite);
    };
}
