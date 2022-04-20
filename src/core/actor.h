#pragma once

#include "sprite.h"

namespace game::core {
    class Actor {
    private:
        std::shared_ptr<game::core::Sprite> sprite_;

    public:
        Actor() = delete;

        explicit Actor(std::shared_ptr<game::core::Sprite> sprite);

        Actor(const game::core::Actor &actor) = delete;

        Actor &operator=(const Actor &) = delete;

        virtual ~Actor();

        [[nodiscard]] const std::shared_ptr<game::core::Sprite> &sprite() const;

        void sprite(std::shared_ptr<game::core::Sprite> sprite);
    };
}
