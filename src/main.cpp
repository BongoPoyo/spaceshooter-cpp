// Normal Libraries
#include <iostream>
#include <math.h>
#include <cstdlib>
// SFML Libraries
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
// Using namespaces
using namespace std;
using namespace sf;

struct Player
{
  Vector2f pos;
  int health = 3;
  Sprite sprite(texture);
};

int main() 
{
  RenderWindow window(VideoMode({800, 600}), "SFML window");
  window.setFramerateLimit(60);


  const Texture texture("sprites/player.png");
  struct Player player;
  player.sprite.setTexture(texture);
  player.pos = {400, 580};
  player.sprite.setPosition(player.pos);

  // Sprite sprite(texture);
  // Vector2f position = {400, 580};

  while (window.isOpen()) 
  {
    while (const optional event = window.pollEvent()) 
    {
      if (event->is<Event::Closed>())
        window.close();
    }

    // if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    //   position.x -= 5;
    // if (Keyboard::isKeyPressed(Keyboard::Key::Right))
    //   position.x += 5;
    
    // if(position.x >= 770)
    // {
    //   position.x = 770;
    // }
    // if(position.x <= 0)
    // {
    //   position.x = 0;
    // }
    //sprite.setPosition(position);

    window.clear();
    window.draw(player.sprite);
    window.display();
  }
}
