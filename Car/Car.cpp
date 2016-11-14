#include "stdafx.h"
#include "Car.h"

const std::map<Gear, std::pair<Direction, std::pair<int, int>>> GEARS = 
{
    { Gear::REVERSE, { Direction::BACKWARD,{ 0, 20 } } },
    { Gear::NEUTRAL, { Direction::NONE,{ 0, 150 } } },
    { Gear::FIRST, { Direction::FORWARD,{ 0, 30 } } },
    { Gear::SECOND, { Direction::FORWARD,{ 20, 50 } } },
    { Gear::THIRD, { Direction::FORWARD,{ 30, 60 } } },
    { Gear::FOURTH, { Direction::FORWARD,{ 40, 90 } } },
    { Gear::FIFTH, { Direction::FORWARD,{ 50, 150 } } }
};

bool CCar::IsSpeedInGearRange(int speed, Gear gear)
{
    return (speed >= GEARS.at(gear).second.first && speed <= GEARS.at(gear).second.second);
}

void CCar::SetDirection(int speed)
{
    if (speed < 0)
    {
        m_direction = Direction::BACKWARD;
    }
    else if (speed == 0)
    {
        m_direction = Direction::NONE;
    }
    else if (speed > 0)
    {
        m_direction = Direction::FORWARD;
    }
}

bool CCar::IsValidDirectionForGear(Gear gear)
{
    return ((gear == Gear::REVERSE && m_direction == Direction::NONE)
        || (gear == Gear::NEUTRAL)
        || (gear != Gear::REVERSE && m_direction == GEARS.at(static_cast<Gear>(static_cast<int>(gear) - 1)).first));
}

bool CCar::IsEngineTurnOn() const
{
    return m_isEngineTurnOn;
}

Gear CCar::GetGear() const
{
    return m_gear;
}

int CCar::GetSpeed() const
{
    return m_speed;
}

Direction CCar::GetDirection() const
{
    return m_direction;
}

bool CCar::TurnOnEngine()
{
    return (!m_isEngineTurnOn) ? m_isEngineTurnOn = true : false;
}

bool CCar::TurnOffEngine()
{
    if (m_isEngineTurnOn && m_speed == 0)
    {
        m_isEngineTurnOn = false;
        return true;
    }
    return false;
}

bool CCar::SetGear(Gear gear)
{
    if ((!m_isEngineTurnOn && gear == Gear::NEUTRAL)
        || (m_isEngineTurnOn && IsSpeedInGearRange(m_speed, gear) && IsValidDirectionForGear(gear)))
    {
        m_gear = gear;
        return true;
    }
    return false;
}

bool CCar::SetSpeed(int speed)
{
    if (IsSpeedInGearRange(speed, m_gear) && (m_gear != Gear::NEUTRAL || speed == 0))
    {
        m_speed = speed;
        SetDirection(speed);
        return true;
    }
    return false;
}