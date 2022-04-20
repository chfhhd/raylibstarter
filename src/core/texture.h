#pragma once

#include <raylib.h>

namespace game::core {
    class Texture2D final {
    public:
        Texture2D() = delete;

        explicit Texture2D(const char *filename);

        Texture2D(const game::core::Texture2D &texture) = delete;

        Texture2D &operator=(const Texture2D &) = delete;

        ~Texture2D();

        [[nodiscard]] const ::Texture2D &texture() const;

        [[nodiscard]] const int &width() const;

        [[nodiscard]] const int &height() const;

    private:
        ::Texture2D texture_ = { };
    };

}
