#pragma once

#include <memory>

#include <raylib.h>

#include "texture2d.h"

namespace game::core {
    class Sprite {
    protected:
        std::shared_ptr<game::core::Texture2D> texture_;
        Rectangle frame_;

    public:
        bool visible = true;
        Color tint = WHITE;
        Vector2 rotation_origin;
        float rotation = 0.0f;
        int pos_x = 0;
        int pos_y = 0;

        Sprite() = delete;

        explicit Sprite(std::shared_ptr<game::core::Texture2D> texture);

        Sprite(std::shared_ptr<game::core::Texture2D> texture, int pos_x, int pos_y);

        Sprite(std::shared_ptr<game::core::Texture2D> texture, int pos_x, int pos_y, float rotation);

        Sprite(std::shared_ptr<game::core::Texture2D> texture, int pos_x, int pos_y, Vector2 rotation_origin, float rotation, Rectangle frame);

        virtual ~Sprite();

        void texture(const std::shared_ptr<game::core::Texture2D> &texture);

        [[maybe_unused]] [[nodiscard]] const std::shared_ptr<game::core::Texture2D> &texture_object() const;

        [[nodiscard]] const ::Texture2D &texture() const;

        [[nodiscard]] Vector2 position() const;

        [[nodiscard]] const Rectangle &frame() const;

        void frame(const Rectangle &frame);

        virtual void Update() { };
    };
}
