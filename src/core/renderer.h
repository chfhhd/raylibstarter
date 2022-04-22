#pragma once

#include <raylib.h>

#include "scene.h"
#include "sprite.h"

namespace game::core {
    /**
     * @brief A central place for graphics and rendering oriented functions
     */
    class Renderer final {
    public:
        /**
        * @brief Sprite object to be drawn. Oriented to the size, position and rotation angle of the sprite object.
        * @param sprite Sprite object to be drawn.
        */
        static void DrawTexture(const std::shared_ptr<game::core::Sprite> &sprite);
    };
}
