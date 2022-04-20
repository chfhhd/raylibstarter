#include <raylib.h>

#include "game.h"

#include "store.h"
#include "stage.h"
#include "renderer.h"
#include "../scenes/scenes.h"

using namespace std::string_literals;

game::core::Game::Game(int stage_width, int stage_height, bool full_screen, int target_fps, int window_flags,
                       int exit_key, bool mouse, bool audio, const char *project_name)
                       : stage_width_(stage_width), stage_height_(stage_height), audio_(audio), mouse_(mouse) {
    SetConfigFlags(window_flags);
    InitWindow(stage_width, stage_height, project_name);
    SetWindowMinSize(stage_width / 2, stage_height / 2);
    SetTargetFPS(target_fps);

    SetExitKey(exit_key);

    if (full_screen)
        ToggleFullscreen();

    if (audio)
        InitAudioDevice();

    if (!mouse)
        HideCursor();
}

game::core::Game::~Game() {
    if (this->audio_)
        CloseAudioDevice();

    // Close window and OpenGL context
    CloseWindow();
}

void game::core::Game::Run(const std::string& scene_name, std::unique_ptr<game::core::Scene> scene) const {
    // Render texture initialization, used to hold the rendering result, so we can easily resize it
    RenderTexture2D target = LoadRenderTexture(this->stage_width_, this->stage_height_);
    // Set texture scale filter to use
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);

    // Create game::Stage instance and assign new scene
    game::core::Store::stage = std::make_unique<game::core::Stage>(scene_name, std::move(scene));

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button if defined
    {
        if(this->mouse_)
            game::core::Renderer::UpdateMousePosition(this->stage_width_, this->stage_height_);

        // Process input and update current active scene
        game::core::Store::stage->Update();

        // Draw
        BeginDrawing();
        ClearBackground(BLACK); // Letterbox color

        // Draw everything in the render texture, note this will not be rendered on screen, yet
        BeginTextureMode(target);
        // Draw the current active scene to render texture
        game::core::Store::stage->Draw();
        EndTextureMode();

        // Draw render texture to window, properly scaled
        game::core::Renderer::DrawRenderTexture(target, this->stage_width_, this->stage_height_);
        EndDrawing();

        // Increment game tick counter
        game::core::Store::ticks++;
    } // Main game loop end

    // Unload render texture
    UnloadRenderTexture(target);
}
