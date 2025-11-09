#pragma once
#include <raylib.h>
#include <iostream>

struct Laser {
  Vector2 laser_position;
  int laser_speed;
  bool laser_active;
  
  void initialize(Vector2 position, int speed) {
  {
    laser_position = position;
    laser_speed = speed;
    active=true;
  }
  void update()
  {
    position.y += speed;
    if (active)
    {
      if(laser_position.y > GetScreenHeight() || laser_position.y < 0)
      {
        active = false;
        std::cout << "Laser Inactive";
      }
    }
  }

  void draw(){
    if(active) 
    {
      DrawRectangle(laser_position.x, laser_position.y, 4, 15, {243,216,63,255});
    }
  }
}

