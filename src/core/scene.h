#pragma once

#include <map>
#include <string>

#include <raylib.h>

#include "actor.h"

namespace game::core {
    /**
     * Scenes are one basic element of this engine. They contain the actual game-play elements. Scene classes derived
     * from this base class implement an Update() method to manipulate the game state and draw graphics via the Draw()
     * method to be implemented.
     *
     * A scene object contains actors that are automatically drawn by the Stage object. Actors can be placed in
     * the actor-map of a scene object and will be drawn automatically if their visible attribute is true.
     * If actor objects are supposed to be available across scenes, they can also be stored in game::core::actors.
     * Objects that are only referenced there will not be drawn automatically.
     *
     * @brief Scene base class. Scene objects are managed by the Stage object.
     */
    class Scene {
    public:
        std::map<std::string, std::shared_ptr<game::core::Actor>> actors = { };

        Scene() {
            TraceLog(LOG_INFO, "game::core::Scene constructor called");
        }

        virtual ~Scene() {
            TraceLog(LOG_INFO, "game::core::Scene destructor called");
        }

        /**
         * Create a new Actor object.
         * @brief Constructor.
         * @param sprite Sprite object that is assigned to the Actor.
         */
        virtual void Update() = 0;

        /**
         * Create a new Actor object.
         * @brief Constructor.
         * @param sprite Sprite object that is assigned to the Actor.
         */
        virtual void Draw() = 0;
    };
}
