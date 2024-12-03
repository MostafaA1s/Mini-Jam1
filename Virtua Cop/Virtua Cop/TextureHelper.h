#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>

class TextureHelper {
public:
    static TextureHelper& getInstance();

    void loadTexture(const std::string& filePath, sf::Sprite& sprite);

private:
    TextureHelper() = default;
    ~TextureHelper() = default;

    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;

    TextureHelper(const TextureHelper&) = delete;
    TextureHelper& operator=(const TextureHelper&) = delete;
};
