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

    switch (type) 
    {
      case 1:
        image = LoadTexture("sprites/alien-1.png");
        break;
      case 2:
        image = LoadTexture("sprites/alien-2.png");
        break;
      case 3:
        image = LoadTexture("sprites/alien-3.png");
        break;
      default:
        image = LoadTexture("sprites/alien-1.png");
        break;
    }
  }

  void update()
  {

  }

  void draw() 
  {
    DrawTextureV(image, position, WHITE);
  }

  int get_type() {
    return type;
  }
};
