#include "stdafx.h"
#include "CarController.h"

std::string DirectionToString(Direction direction)
{
    switch (direction)
    {
    case Direction::NONE:
        return "������";
    case Direction::FORWARD:
        return "�����";
    case Direction::BACKWARD:
        return "�����";
    default:
        return "";
    }
}

std::string GearToString(Gear gear)
{
    switch (gear)
    {
    case Gear::REVERSE:
        return "������";
    case Gear::NEUTRAL:
        return "�����������";
    case Gear::FIRST:
        return "������";
    case Gear::SECOND:
        return "������";
    case Gear::THIRD:
        return "�������";
    case Gear::FOURTH:
        return "���������";
    case Gear::FIFTH:
        return "�����";
    default:
        return "";
    }
}

void PrintHelp(std::ostream &out)
{
    out << "info: ����� ��������� ��������� ����������, ����������� ��������, �������� � ��������.\n"
        << "engineon: ������ ���������.\n"
        << "engineoff: ���������� ���������.\n"
        << "setgear <��������>: ��������� �������� ��������. � ������ ������ �������� � ������� ������������� ������������ ��������.\n"
        << "setspeed <��������>: ��������� ��������� �������� ��������. � ������ ������������� ��������� �������� �������� � ������� ������������� �������� �������� �� ���������.\n"
        << "exit: ����� �� ���������.\n";
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
        m_out << "���������� " << (m_car.IsEngineTurnOn() ? "�������" : "��������") << ", "
            << "��������� " << DirectionToString(m_car.GetDirection()) << ", "
            << "�� ��������� " << m_car.GetSpeed() << ", "
            << "�� " << GearToString(m_car.GetGear()) << " ��������.\n";
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
            m_out << "���������� ����������� ��������\n";
            return false;
        }
    }
    else if (commands[0] == "setspeed")
    {
        if (!m_car.SetSpeed(atoi(commands[1].c_str())))
        {
            if (!m_car.IsEngineTurnOn())
            {
                m_out << "������ �������� �������� ��� ����������� ���������\n";
                return false;
            }
            else
            {
                m_out << "��������� �������� �� �������� � ������� ��������\n";
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