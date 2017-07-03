#ifndef GAME_RESSOURCES_TILE_PARSER_HPP
#define GAME_RESSOURCES_TILE_PARSER_HPP

#include <vector>

#include <SFML/Graphics/Sprite.hpp>

namespace Ressources {

class TileManager {
 public:
  size_t parseTexture(const sf::Texture& texture, size_t tileSize);
  const std::vector<sf::Sprite>& tiles() const;
  const sf::Sprite& tile(size_t index) const;

 private:
  std::vector<sf::Sprite> _tiles;
};

} /* namespace Ressources */

#endif
