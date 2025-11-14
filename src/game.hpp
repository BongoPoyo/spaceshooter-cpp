#pragma once // To open this library only once
#include "alien.hpp"
#include "obstacle.hpp"  // To include the obstacle file's struct
#include "spaceship.hpp" // To include spaceship file's functions

int alien_direction = 1; // Global variable to use it in the move_alien function and passing it as an argument to update() function in the alien.hpp file
constexpr static float alien_laser_interval = 0.35; // Global variable to calculate the laser shooting interval by aliens
float alien_fired_last_time = 0.0;
std::vector<Obstacle>
    obstacles; // A universial vector variable to store obstacles so we can
               // store it and use it in game_initialize function
std::vector<Alien> aliens;
std::vector<Laser> alien_lasers;

// To avoid cross referencing we put the create obstacle function in the game
// header file
std::vector<Obstacle> obstacle_create() {
  int obstacle_width = Obstacle({100, 100}).grid[0].size() * 3;
  float obstacle_gap =
      (GetScreenWidth() - (4 * obstacle_width)) / 5.0f; // Takes the gap between two obstacles by taking the width of all
            // the 4 obstacles and subtracting it from the screen width and
            // dividing it by 5 cause for 4 obstacles you have to add 5 gaps ( 3
            // for each other and 2 for the parameters of the screen )
  for (int i = 0; i != 4; i++) // Running it exactly 4 times to create 4 objects
                               // and later draw them
  {
    float obstacle_position_x =
        (i + 1) * obstacle_gap +
        i * obstacle_width; // To calculate the x position of the obstacle by
                            // ensuring they are evenly spaced
    float obstacle_position_y = GetScreenHeight() - 100;
    obstacles.push_back(Obstacle({obstacle_position_x, obstacle_position_y}));
  }
  return obstacles;
}

void game_uninitialize()
 {
  for (auto &alien : aliens) 
  {
    alien.uninitalize();
    aliens.pop_back();
  }
 }
void game_draw()
{
  spaceship_draw(); // Draw the spaceship from the spaceship header file
  //
  for (auto &laser : spaceship_lasers) {
    laser.draw();
  }
  for (auto &obstacle : obstacles) {
    obstacle.draw();
  }
  for (auto &alien : aliens) {
    alien.draw();
  }
  for(auto &laser: alien_lasers)
  {
    laser.draw();
  }
}

std::vector<Alien> create_aliens() {
  std::vector<Alien> temp_aliens;
  for (int row = 0; row < 5; row++) {
    for (int column = 0; column < 11; column++) {

      int alien_type = 1;

      if (row == 0) {
        alien_type = 3;
      } else if (row == 1 || row == 2) {
        alien_type = 2;
      }
      float x = column * 55;
      float y = row * 55;
      temp_aliens.push_back(Alien(alien_type, {x + 75, y + 110}));
    }
  }
  return temp_aliens;
}

void alien_laser() // To shoot lasers from the aliens
{
  double current_time = GetTime();
  if(current_time - alien_fired_last_time >= alien_laser_interval && !aliens.empty())
  {
  int random_value = GetRandomValue(0, aliens.size()-1); 
  Alien& alien = aliens[random_value]; 
  alien_lasers.push_back(Laser({alien.position.x + alien.image[alien.type - 1 ].width/2,
                               alien.position.y + alien.image[alien.type - 1].height}, 6));
  alien_fired_last_time = GetTime();
  }
}

void alien_move_down(int distance) // To move the aliens down in the game.hpp file by calling this function in the alien_move function
{
  for(auto& alien: aliens)
  {
    alien.position.y = alien.position.y + distance;
  }
}

void alien_move() // To move the aliens horizontally in the game.hpp file by calling a function update() from the alien struct
{
  for(auto& alien: aliens)
  {
    if(alien.position.x + alien.image[alien.type-1].width>GetScreenWidth()) // To avoid aliens getting out from the right side of the window screen
    {
      alien_direction = -1; // We make them move left if they collide from the right boundary of the screen
      alien_move_down(2); // To move the alien 4 pixels down
    }
    if(alien.position.x < 0) // To avoid aliens getting out from the left side of the window screen
    {
      alien_direction = 1; // We make them move right if they collide from the left boundary of the screen
      alien_move_down(2);
    }
    alien.update(alien_direction);
  }
}

void game_initialize() {
  spaceship_initialize();
  obstacles = obstacle_create();
  aliens = create_aliens();
}

// To avoid cross referencing we put the delete laser function in the game
// header file
void laser_delete() {
  for (auto laser = spaceship_lasers.begin();
       laser != spaceship_lasers.end();) {
    if (!laser->active) {
      laser = spaceship_lasers.erase(laser);
    } else {
      ++laser;
    }
  }

  for (auto laser = alien_lasers.begin();
       laser != alien_lasers.end();) {
    if (!laser->active) {
      laser = alien_lasers.erase(laser);
    } else {
      ++laser;
    }
  }
}

void game_update() {
  spaceship_boundaries();

  for (auto &laser : spaceship_lasers) {
    laser.update();
  }
  laser_delete();

  for (auto &obstacle : obstacles) {
    obstacle.draw();
  }
  alien_laser();
  for(auto& laser: alien_lasers)
  {
    laser.update();
  }
  alien_move();
}

void handle_input() {
  if (IsKeyDown(KEY_LEFT)) {
    spaceship_position.x = spaceship_position.x - 5;
  } else if (IsKeyDown(KEY_RIGHT)) {
    spaceship_position.x = spaceship_position.x + 5;
  }
  if (IsKeyDown(KEY_SPACE)) {
    spaceship_fire_laser();
  }

  if (IsKeyDown(KEY_Q)) {
    CloseWindow();
  }
}
