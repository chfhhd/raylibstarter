#include "store.h"
#include "stage.h"
#include "renderer.h"

Vector2 game::core::Renderer::ClampValue(Vector2 value, Vector2 MIN, Vector2 MAX) {
    Vector2 result = value;

    result.x = (result.x > MAX.x) ? MAX.x : result.x;
    result.x = (result.x < MIN.x) ? MIN.x : result.x;
    result.y = (result.y > MAX.y) ? MAX.y : result.y;
    result.y = (result.y < MIN.y) ? MIN.y : result.y;

    return result;
}

void game::core::Renderer::UpdateMousePosition(int stage_width, int stage_height) {
    // Compute required framebuffer scaling
    float scale = MIN((float) GetScreenWidth() / stage_width, (float) GetScreenHeight() / stage_height);

    // Update virtual mouse (clamped mouse value behind game screen)
    Vector2 mouse = GetMousePosition();
    Store::mouse_position.x = (mouse.x - (static_cast<float>(GetScreenWidth()) - (static_cast<float>(stage_width) * scale)) * 0.5f) / scale;
    Store::mouse_position.y = (mouse.y - (static_cast<float>(GetScreenHeight()) - (static_cast<float>(stage_height) * scale)) * 0.5f) / scale;
    Store::mouse_position = ClampValue(Store::mouse_position, {0, 0}, {static_cast<float>(stage_width), static_cast<float>(stage_height)});
}

void game::core::Renderer::DrawRenderTexture(RenderTexture2D target, int stage_width, int stage_height) {
    // Compute required framebuffer scaling
    float scale = MIN((float) GetScreenWidth() / stage_width, (float) GetScreenHeight() / stage_height);

    // Draw RenderTexture2D to window, properly scaled
    DrawTexturePro(target.texture,
                   {0.0f, 0.0f, static_cast<float>(target.texture.width), static_cast<float>(-target.texture.height)},
                   {(static_cast<float>(GetScreenWidth()) - (static_cast<float>(stage_width) * scale)) * 0.5f,
                    (static_cast<float>(GetScreenHeight()) - (static_cast<float>(stage_height) * scale)) * 0.5f,
                    static_cast<float>(stage_width) * scale, static_cast<float>(stage_height) * scale},
                    {0.0f, 0.0f}, 0.0f, WHITE
                    );
}

void game::core::Renderer::DrawTexture(const std::shared_ptr<game::core::Sprite>& sprite) {
    DrawTexturePro(sprite->texture(), sprite->frame(),
                   {(static_cast<float>(sprite->pos_x) + sprite->rotation_origin.x), (static_cast<float>(sprite->pos_y) + sprite->rotation_origin.y),
                    static_cast<float>(sprite->frame().width), static_cast<float>(sprite->frame().height)},
                   sprite->rotation_origin, sprite->rotation, sprite->tint);
}
