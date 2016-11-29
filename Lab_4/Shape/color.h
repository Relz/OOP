#pragma once
struct Color
{
    float r;
    float g;
    float b;
};
Color HexToRGB(std::string const& hexColor);