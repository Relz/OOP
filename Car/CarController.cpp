#include "stdafx.h"
#include "CarController.h"

std::string DirectionToString(Direction direction)
{
    switch (direction)
    {
    case Direction::NONE:
        return "никуда";
    case Direction::FORWARD:
        return "вперёд";
    case Direction::BACKWARD:
        return "назад";
    default:
        return "";
    }
}

std::string GearToString(Gear gear)
{
    switch (gear)
    {
    case Gear::REVERSE:
        return "задней";
    case Gear::NEUTRAL:
        return "нейтральной";
    case Gear::FIRST:
        return "первой";
    case Gear::SECOND:
        return "второй";
    case Gear::THIRD:
        return "третьей";
    case Gear::FOURTH:
        return "четвертой";
    case Gear::FIFTH:
        return "пятой";
    default:
        return "";
    }
}

void PrintHelp(std::ostream &out)
{
    out << "info: Вывод состояния двигателя автомобиля, направление движения, скорость и передачу.\n"
        << "engineon: Запуск двигателя.\n"
        << "engineoff: Выключение двигателя.\n"
        << "setgear <передача>: Включение заданной передачи. В случае ошибки сообщает о причине невозможности переключения передачи.\n"
        << "setspeed <скорость>: Установка указанной скорости движения. В случае невозможности изменения скорости сообщает о причине невозможности изменить скорость на указанную.\n"
        << "exit: Выход из программы.\n";
}

CCarController::CCarController(CCar & car, std::istream &in, std::ostream &out)
    : m_car(car)
    , m_in(in)
    , m_out(out)
{
}

bool CCarController::GetCommand(std::vector<std::string> & command)
{
    m_out << "> ";
    std::string commandLine;
    if (m_doExit || !getline(m_in, commandLine))
    {
        return false;
    }
    std::string lowerCasedCommandLine;
    lowerCasedCommandLine.resize(commandLine.length());
    std::transform(commandLine.begin(), commandLine.end(), lowerCasedCommandLine.begin(), ::towlower);
    boost::split(command, lowerCasedCommandLine, boost::is_any_of(" "));
    return true;
}

bool CCarController::HandleCommand(std::vector<std::string> const& commands)
{
    if (commands.empty())
    {
        return false;
    }
    if (REQUIRED_COMMAND_ARG_COUNT.find(commands[0]) == REQUIRED_COMMAND_ARG_COUNT.end())
    {
        m_out << "Unknown command: \"" << commands[0] << "\"\n";
        return false;
    }
    if (REQUIRED_COMMAND_ARG_COUNT.at(commands[0]) != commands.size() - 1)
    {
        m_out << "Command \"" << commands[0] << "\" requires " << REQUIRED_COMMAND_ARG_COUNT.at(commands[0]) << " arguments \n"
            << "For more details, see \"help\"\n";
        return false;
    }
    if (commands[0] == "info")
    {
        m_out << "Автомобиль " << (m_car.IsEngineTurnOn() ? "включён" : "выключен") << ", "
            << "направлен " << DirectionToString(m_car.GetDirection()) << ", "
            << "со скоростью " << m_car.GetSpeed() << ", "
            << "на " << GearToString(m_car.GetGear()) << " передаче.\n";
    }
    else if (commands[0] == "engineon")
    {
        m_car.TurnOnEngine();
    }
    else if (commands[0] == "engineoff")
    {
        m_car.TurnOffEngine();
    }
    else if (commands[0] == "setgear")
    {
        if (!m_car.SetGear(static_cast<Gear>(atoi(commands[1].c_str()))))
        {
            m_out << "Невозможно переключить передачу\n";
            return false;
        }
    }
    else if (commands[0] == "setspeed")
    {
        if (!m_car.SetSpeed(atoi(commands[1].c_str())))
        {
            if (!m_car.IsEngineTurnOn())
            {
                m_out << "Нельзя изменить скорость при выключенном двигателе\n";
                return false;
            }
            else
            {
                m_out << "Указанная скорость не доступна в текущей передаче\n";
                return false;
            }
        }
    }
    else if (commands[0] == "help")
    {
        PrintHelp(m_out);
    }
    else if (commands[0] == "exit")
    {
        m_doExit = true;
    }
    
    return true;
}