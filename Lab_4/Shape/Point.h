#pragma once
class CPoint final
{
public:
    CPoint() = default;
    CPoint(float x, float y);
    std::string ToString() const;
    float x = 0.0; 
    float y = 0.0;
};

bool operator >> (std::istream & in, CPoint & point);