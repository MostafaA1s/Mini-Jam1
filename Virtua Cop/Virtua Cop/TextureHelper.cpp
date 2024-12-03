#include "TextureHelper.h"

TextureHelper& TextureHelper::getInstance() {
    static TextureHelper instance;
    return instance;
}

void TextureHelper::loadTexture(const std::string& filePath, sf::Sprite& sprite) {
    if (textures.find(filePath) == textures.end()) {
        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(filePath)) {
            std::cerr << "Error: Failed to load texture from " << filePath << std::endl;
            return;
        }
        textures[filePath] = std::move(texture);
    }

    sprite.setTexture(*textures[filePath]);
}
