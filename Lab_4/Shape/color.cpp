#include "stdafx.h"
#include "color.h"

sf::Color HexToRGB(std::string const& hexColor)
{
    sf::Color result;
    bool isConverted = true;
    try
    {
        result.r = static_cast<sf::Uint8>(std::stoi(hexColor.substr(0, 2), 0, 16));
        result.g = static_cast<sf::Uint8>(std::stoi(hexColor.substr(2, 2), 0, 16));
        result.b = static_cast<sf::Uint8>(std::stoi(hexColor.substr(4, 2), 0, 16));
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}