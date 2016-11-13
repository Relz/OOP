#include "stdafx.h"
#include "Car.h"

bool CCar::IsEngineTurnOn() const
{
    return false;
}

bool CCar::IsNeutralGear() const
{
    return false;
}

bool CCar::TurnOnEngine()
{
    return false;
}

bool CCar::TurnOffEngine()
{
    return false;
}

Gear CCar::GetGear() const
{
    return Gear::NEUTRAL;
}

int CCar::GetSpeed() const
{
    return 0;
}

Direction CCar::GetDirection() const
{
    return Direction::NONE;
}

bool CCar::SetGear(Gear gear)
{
    return false;
}

bool CCar::SetSpeed(int speed)
{
    return false;
}