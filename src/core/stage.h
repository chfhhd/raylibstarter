#pragma once

#include <memory>
#include <string>

#include <raylib.h>
#include <map>

#include "scene.h"
#include "sprite.h"

namespace game::core {
    class Stage final {
    public:
        Stage() = delete;

        Stage(const std::string& new_scene_name, std::unique_ptr<game::core::Scene> scene);

        Stage(const game::core::Stage &stage) = delete;

        Stage &operator=(const Stage &) = delete;

        virtual ~Stage() = default;

        [[nodiscard]] const std::shared_ptr<game::core::Scene> &scene() const;

        [[nodiscard]] const std::map<std::string, std::shared_ptr<game::core::Scene>> &scenes() const;

        void replaceWithNewScene(const std::string& old_scene_name, const std::string& new_scene_name, std::shared_ptr<Scene> scene);

        void replaceWithExistingScene(const std::string& old_scene_name, const std::string& new_scene_name);

        void switchToNewScene(const std::string& new_scene_name, std::shared_ptr<Scene> scene);

        void switchToScene(const std::string& new_scene_name);

        void Update();

        void Draw();

    private:
        std::shared_ptr<game::core::Scene> scene_;

        std::shared_ptr<game::core::Scene> next_scene_;

        std::map<std::string, std::shared_ptr<game::core::Scene>> scenes_;

    };
}
