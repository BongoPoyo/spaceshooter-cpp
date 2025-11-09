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


int main() 
{
  RenderWindow window(VideoMode({800, 600}), "SFML window");
  window.setFramerateLimit(60);
  const Texture texture("sprites/player.png");
  Sprite sprite(texture);
  while (window.isOpen()) 
  {
    while (const optional event = window.pollEvent()) 
    {
      if (event->is<Event::Closed>())
        window.close();
    }
    window.clear();
    window.draw(sprite);
    window.display();
  }
}
