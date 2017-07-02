#include <SFML/Window.hpp>

#include "TextureManager.hpp"

class Window {
 public:
  Window()
    : _window(sf::VideoMode(800, 600), "TileManager") {}

  void run() {
    sf::Event event;

    this->init();

    while (_window.isOpen()) {
      while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          this->close();
        }
      }
    }
  }

  void init() {
    _textureManager.load("main", "asset.png");

    _textureManager.get("main");
  }

  void close() {
    _window.close();
  }

 private:
  sf::Window _window;
  TileManager::TextureManager _textureManager;
};

int main() {
  Window window;

  window.run();
  return 0;
}
