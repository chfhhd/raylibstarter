#pragma once

#include <vector>

#include <raylib.h>

#include "texture2d.h"
#include "sprite.h"

namespace game::core {
    class SpriteAnimated : public game::core::Sprite {
    public:
        SpriteAnimated() = delete;

        SpriteAnimated(std::shared_ptr<game::core::Texture2D> texture, float frame_width, float frame_height,
                       int row,
                       int steps,
                       int speed);

        SpriteAnimated(std::shared_ptr<game::core::Texture2D> texture, float frame_width, float frame_height,
                       int row,
                       int steps,
                       int speed,
                       int pos_x,
                       int pos_y);

        SpriteAnimated(std::shared_ptr<game::core::Texture2D> texture, float frame_width, float frame_height,
                       int row,
                       int steps,
                       int speed,
                       int pos_x,
                       int pos_y,
                       float rotation);

        [[nodiscard]] int state() const;

        void Update() override;

        void AddState(int row, int steps, int speed, float frame_width,float frame_height);

        void nextState(int nextState);

        bool update_if_invisible = false;

    private:
        struct anim_state {
            int row;
            int steps;
            int speed;
            float frame_width;
            float frame_height;
        };

        int state_ = 0;
        int next_state_ = 0;
        int current_step_ = 0;

        std::vector<anim_state> states_;

        void SwitchState();
        void state(int state);
    };
}
