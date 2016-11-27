#pragma once
class CPoint final
{
public:
    CPoint() = default;
    CPoint(double x, double y);
    ~CPoint() = default;
    std::string ToString() const;
    double x = 0.0; 
    double y = 0.0;
};

bool operator >> (std::istream & in, CPoint & point);