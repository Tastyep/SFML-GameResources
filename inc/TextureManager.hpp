#ifndef TILE_MANAGER_TEXTURE_MANAGER_HPP
#define TILE_MANAGER_TEXTURE_MANAGER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>

namespace TileManager {

class TextureManager {
 public:
  bool load(std::string name, const std::string& imagePath);
  const sf::Texture& get(const std::string& name) const;

 private:
  std::unordered_map<std::string, sf::Texture> _textures;
};

} /* namespace TileManager */

#endif
