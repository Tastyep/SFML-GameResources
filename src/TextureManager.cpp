#include "TextureManager.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

#include <spdlog/fmt/ostr.h>

namespace TileManager {

bool TextureManager::load(std::string name, const std::string& imagePath) {
  sf::Texture texture;

  if (_textures.find(name) != _textures.end()) {
    std::cerr << "A texture is already registered for the name \"" << name << "\"" << std::endl;
    return false;
  }
  if (!texture.loadFromFile(imagePath)) {
    std::cerr << "Could not find the image '" << imagePath << "'" << std::endl;
    return false;
  }

  _textures.emplace(std::move(name), std::move(texture));
  return true;
}

const sf::Texture& TextureManager::get(const std::string& name) const {
  auto it = _textures.find(name);

  if (it != _textures.end()) {
    return it->second;
  }
  throw std::out_of_range(fmt::format("Texture \"{}\" not found", name));
}

} /* namespace TileManager */
