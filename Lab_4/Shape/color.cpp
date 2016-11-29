#include "stdafx.h"
#include "color.h"

Color HexToRGB(std::string const& hexColor)
{
    Color result;
    bool isConverted = true;
    try
    {
        result.r = (1.f / 255) * std::stoi(hexColor.substr(0, 2), 0, 16);
        result.g = (1.f / 255) * std::stoi(hexColor.substr(2, 2), 0, 16);
        result.b = (1.f / 255) * std::stoi(hexColor.substr(4, 2), 0, 16);
    }
    catch (std::exception const& e)
    {
        std::cout << e.what() << std::endl;
    }
    return result;
}