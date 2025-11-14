#pragma once
#include<raylib.h>

struct Alien {
  Texture2D image;
  int type;
  Vector2 position;

  Alien(int i_type, Vector2 i_position)
  {
    position = i_position;
    type = i_type;
  }

  void update()
  {

  }

  void draw() 
  {

  }

  void return_type() {

  }
}
