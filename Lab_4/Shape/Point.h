#pragma once
class CPoint
{
public:
    CPoint() = default;
    CPoint(double x, double y);
    ~CPoint() = default;
    std::string ToString() const;
    double x = 0.0; 
    double y = 0.0;
};

