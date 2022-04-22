#pragma once

#include <map>

#include <raylib.h>

#include "stage.h"
#include "actor.h"

namespace game::core {
    /**
     * @brief A central place to share globally accessible objects that should be accessible from anywhere.
     */
    struct Store final {
         inline static std::unique_ptr<game::core::Stage> stage = nullptr;

         inline static Vector2 mouse_position = { };

         inline static long long int ticks = 1;

         inline static std::map<std::string, std::shared_ptr<game::core::Actor>> actors = { };
    };
}
