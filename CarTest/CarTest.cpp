#include "stdafx.h"
#include "..\Car\Car.h"
#include <iostream>

struct CarFixture
{
    CCar car;
};

void CheckCarGearForSpeedRange(CCar &car, Gear gear, int minSpeed, int maxSpeed)
{
    car.SetGear(gear);
    BOOST_CHECK(car.SetSpeed(minSpeed) && car.GetSpeed() == minSpeed);
    BOOST_CHECK(car.SetSpeed(maxSpeed) && car.GetSpeed() == maxSpeed);
    int speedBeforeSetSpeed = car.GetSpeed();
    BOOST_CHECK(!car.SetSpeed(minSpeed - 1) && car.GetSpeed() == speedBeforeSetSpeed);
    BOOST_CHECK(!car.SetSpeed(maxSpeed + 1) && car.GetSpeed() == speedBeforeSetSpeed);
}

// Класс CCar
BOOST_FIXTURE_TEST_SUITE(CCar_class, CarFixture)

// Двигатель автомобиля по-умолчанию выключен
BOOST_AUTO_TEST_CASE(engine_is_turned_off_by_default)
{
    BOOST_CHECK(!car.IsEngineTurnOn());
}

// Автомобиль по-умолчанию стоит на нейтральной передаче
BOOST_AUTO_TEST_CASE(gear_is_neutral_by_default)
{
    BOOST_CHECK(car.GetGear() == Gear::NEUTRAL);
}

// Автомобиль по-умолчанию не имеет скорости
BOOST_AUTO_TEST_CASE(speed_is_zero_by_default)
{
    BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
}

// Автомобиль по-умолчанию не имеет направления
BOOST_AUTO_TEST_CASE(direction_is_none_by_default)
{
    BOOST_CHECK(car.GetDirection() == Direction::NONE);
}

// Выключенный по-умолчанию двигатель автомобиля может включиться
BOOST_AUTO_TEST_CASE(turned_off_engine_can_be_turned_on)
{
    BOOST_CHECK(car.TurnOnEngine() && car.IsEngineTurnOn());
}

// Включенный двигатель автомобиля не может снова включиться
BOOST_AUTO_TEST_CASE(turned_on_engine_cannot_be_turned_on)
{
    car.TurnOnEngine();
    BOOST_CHECK(car.IsEngineTurnOn() && !car.TurnOnEngine());
}

// Выключенный двигатель автомобиля не может снова выключиться
BOOST_AUTO_TEST_CASE(turned_off_engine_cannot_be_turned_off)
{
    BOOST_CHECK(!car.TurnOffEngine());
}

// Выключенный двигатель автомобиля может переключить передачу только на нейтральную
BOOST_AUTO_TEST_CASE(can_set_gear_only_to_neutral_if_engine_is_turned_off)
{
    BOOST_CHECK(car.SetGear(Gear::NEUTRAL) && car.GetGear() == Gear::NEUTRAL && car.GetDirection() == Direction::NONE);
    BOOST_CHECK(!car.SetGear(Gear::REVERSE) && car.GetGear() == Gear::NEUTRAL && car.GetDirection() == Direction::NONE);
    BOOST_CHECK(!car.SetGear(Gear::FIRST) && car.GetGear() == Gear::NEUTRAL && car.GetDirection() == Direction::NONE);
    BOOST_CHECK(!car.SetGear(Gear::SECOND) && car.GetGear() == Gear::NEUTRAL && car.GetDirection() == Direction::NONE);
    BOOST_CHECK(!car.SetGear(Gear::THIRD) && car.GetGear() == Gear::NEUTRAL && car.GetDirection() == Direction::NONE);
    BOOST_CHECK(!car.SetGear(Gear::FOURTH) && car.GetGear() == Gear::NEUTRAL && car.GetDirection() == Direction::NONE);
    BOOST_CHECK(!car.SetGear(Gear::FIFTH) && car.GetGear() == Gear::NEUTRAL && car.GetDirection() == Direction::NONE);
}

// Включенный двигатель автомобиля в состоянии покоя может переключить передачу на реверсную или первую передачу
BOOST_AUTO_TEST_CASE(can_set_gear_to_reverse_or_first_if_engine_is_turned_on)
{
    car.TurnOnEngine();
    BOOST_CHECK(car.SetGear(Gear::REVERSE) && car.GetGear() == Gear::REVERSE);
    BOOST_CHECK(car.SetGear(Gear::FIRST) && car.GetGear() == Gear::FIRST);
}

// Включенный двигатель автомобиля может изменить передачу только если скорость в пределах диапазона новой передачи.
BOOST_AUTO_TEST_CASE(can_set_gear_if_engine_is_turned_on_and_speed_within_range)
{
    car.TurnOnEngine();
    BOOST_CHECK(!car.SetGear(Gear::SECOND) && car.GetGear() == Gear::NEUTRAL);
}

// Выключенный двигатель автомобиля не может изменить скорость
BOOST_AUTO_TEST_CASE(cannot_set_speed_if_engine_is_turned_off)
{
    BOOST_CHECK(!car.IsEngineTurnOn() && !car.SetSpeed(1) && car.GetSpeed() == 0 && car.GetDirection() == Direction::NONE);
}

// Включенный автомобиль может изменить скорость только в пределах диапазона её передачи.
// Исключение: на нейтральной передаче изменить скорость можно только в 0
BOOST_AUTO_TEST_CASE(can_set_speed_within_range_if_engine_is_turned_on)
{
    car.TurnOnEngine();
    CheckCarGearForSpeedRange(car, Gear::REVERSE, 0, 20);
    CheckCarGearForSpeedRange(car, Gear::NEUTRAL, 0, 0);
    CheckCarGearForSpeedRange(car, Gear::FIRST, 0, 30);
    CheckCarGearForSpeedRange(car, Gear::SECOND, 20, 50);
    CheckCarGearForSpeedRange(car, Gear::THIRD, 30, 60);
    CheckCarGearForSpeedRange(car, Gear::FOURTH, 40, 90);
    CheckCarGearForSpeedRange(car, Gear::FIFTH, 50, 150);
}

// Включенный двигатель автомобиля можно выключить только в состоянии покоя
BOOST_AUTO_TEST_CASE(turned_on_engine_can_be_turned_off_if_speed_is_zero)
{
    car.TurnOnEngine();
    car.SetGear(Gear::FIRST);
    car.SetSpeed(10);
    BOOST_CHECK(!car.TurnOffEngine());
    car.SetSpeed(0);
    BOOST_CHECK(car.GetSpeed() == 0 && car.TurnOffEngine());
}

BOOST_AUTO_TEST_SUITE_END()