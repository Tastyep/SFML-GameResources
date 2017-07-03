#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "Manager.hpp"
#include "TileManager.hpp"

class Window {
 public:
  Window()
    : _window(sf::VideoMode(800, 600), "TileManager") {}

  void run() {
    sf::Event event;

    _textureManager.load("main", "asset.png");
    const auto& texture = _textureManager.get("main");
    auto nbTiles = _tileManager.parseTexture(texture, 32);

    while (_window.isOpen()) {
      while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          this->close();
        }
      }
      for (size_t i = 0; i < nbTiles; ++i) {
        auto tile = _tileManager.tile(i);

        tile.setPosition(i * 32, 0);
        _window.draw(tile);
      }
      _window.display();
    }
  }

  void close() {
    _window.close();
  }

 private:
  sf::RenderWindow _window;
  Ressources::Manager<sf::Texture> _textureManager;
  Ressources::TileManager _tileManager;
};

int main() {
  Window window;

  window.run();
  return 0;
}
