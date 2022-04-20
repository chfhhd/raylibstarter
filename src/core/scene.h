#pragma once

#include <map>
#include <string>

#include <raylib.h>

#include "actor.h"

namespace game::core {
    class Scene {
    public:
        std::map<std::string, std::shared_ptr<game::core::Actor>> actors = { };

        Scene() {
            TraceLog(LOG_INFO, "game::core::Scene constructor called");
        }

        virtual ~Scene() {
            TraceLog(LOG_INFO, "game::core::Scene destructor called");
        }

        virtual void Update() = 0;

        virtual void Draw() = 0;
    };
}
