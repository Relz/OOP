#pragma once
class CPoint
{
public:
    CPoint() = default;
    CPoint(double x, double y);
    ~CPoint();
    double x = 0.0; 
    double y = 0.0;
};

