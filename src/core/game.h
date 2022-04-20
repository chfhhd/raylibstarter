#pragma once

#include <string>

#include "scene.h"

namespace game::core {
    class Game final {
    private:
        int stage_width_;
        int stage_height_;
        bool audio_;
        bool mouse_;

    public:
        Game() = delete;

        Game(int stage_width, int stage_height, bool full_screen, int target_fps, int window_flags, int exit_key, bool mouse, bool audio, const char *project_name);

        ~Game();

        void Run(const std::string& scene_name, std::unique_ptr<game::core::Scene> scene) const;
    };
}