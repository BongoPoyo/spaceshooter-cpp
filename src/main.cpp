// Normal Libraries
#include<iostream>
#include<vector>
#include<math.h>
// Raylib Libraries
#include<raylib.h>
// My Libraries
#include"game.hpp"
#include"spaceship.hpp"
#include"obstacle.hpp"
#include"enemy.hpp"
#include"alien.hpp"
// Using namespace
using namespace std;

int main(void)
{
    // Setting the window
    Gamestate game_state = Gamestate::Menu;
    const int screen_width = 750;
    const int screen_height = 700;
    InitWindow(screen_width, screen_height, "Space Shooters");
    SetTargetFPS(60);
    InitAudioDevice(); // Sets up the audio according to the device to use it in the game
    game_initialize(); // Call function game

    while (!WindowShouldClose()) // When game is opened
    {
        BeginDrawing();
        ClearBackground(BLACK);

        switch(game_state)
        {
            case Gamestate::Menu:
            draw_menu();
            update_menu();
            break;

            case Gamestate::Level_Select:
            draw_level_select();
            update_level_select();
            break;

            case Gamestate::Game:
            handle_input();
            game_update();
            game_draw();
            break;

            case Gamestate::Game_Over:
            game_over();
            break;
        }
        // DrawText("Congrats! You created your first window!", 0 , 0, 20, GRAY);
        EndDrawing();
    }
    save_highscore_in_file(highscore);
    CloseWindow();
    CloseAudioDevice(); 

    return 0;
}
