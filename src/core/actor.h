#pragma once

#include "sprite.h"

namespace game::core {
    /**
     * Actors can be placed in the actor-map of each scene class and will be drawn automatically if their visible
     * attribute is true. If actor objects are supposed to be available across scenes, they can be stored in
     * game::core::actors. Objects that are only referenced there will not be drawn automatically.
     * The position of an actor object in the game depends on the position of its sprite attribute.
     *
     * @brief Actor base class. Actors represent all game objects, such as players, enemies and other obstacles.
     */
    class Actor {
    private:
        std::shared_ptr<game::core::Sprite> sprite_;

    public:
        Actor() = delete;

        /**
         * Create a new Actor object.
         * @brief Constructor.
         * @param sprite Sprite object that is assigned to the Actor.
         */
        explicit Actor(std::shared_ptr<game::core::Sprite> sprite);

        Actor(const game::core::Actor &actor) = delete;

        Actor &operator=(const Actor &) = delete;

        virtual ~Actor();

        /**
         * @brief Returns the sprite object of the actor
         */
        [[nodiscard]] const std::shared_ptr<game::core::Sprite> &sprite() const;

        /**
         * @brief Replaces the current sprite object of the actor.
         */
        void sprite(std::shared_ptr<game::core::Sprite> sprite);
    };
}
