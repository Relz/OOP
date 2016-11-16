#pragma once

enum class Gear
{
    REVERSE = -1,
    NEUTRAL = 0,
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4,
    FIFTH = 5
};

enum class Direction
{
    BACKWARD = -1,
    NONE = 0,
    FORWARD = 1
};

class CCar
{
public:
    bool IsEngineTurnOn() const;

    Gear GetGear() const;
    int GetSpeed() const;
    Direction GetDirection() const;

    bool TurnOnEngine();
    bool TurnOffEngine();

    bool SetGear(Gear gear);
    bool SetSpeed(int speed);
private:
    bool IsSpeedInGearRange(int speed, Gear gear);
    bool IsValidDirectionForGear(Gear gear);
    bool m_isEngineTurnOn = false;
    Gear m_gear = Gear::NEUTRAL;
    int m_speed = 0;
};