#include "stdafx.h"
#include "CarController.h"

CCarController::CCarController(CCar & car, std::istream & in, std::ostream & out)
    : m_car(car)
    , m_in(in)
    , m_out(out)
{
}

bool CCarController::GetCommand(std::vector<std::string> & command)
{
    m_out << "> ";
    std::string commandLine;
    if (!getline(m_in, commandLine))
    {
        return false;
    }
    std::string lowerCasedCommandLine;
    lowerCasedCommandLine.resize(commandLine.length());
    std::transform(commandLine.begin(), commandLine.end(), lowerCasedCommandLine.begin(), ::towlower);
    boost::split(command, lowerCasedCommandLine, boost::is_any_of(" "));
    return true;
}

void CCarController::HandleCommand(std::vector<std::string> const& commands)
{
    if (commands.empty())
    {
        return;
    }
    if (REQUIRED_COMMAND_ARG_COUNT.find(commands[0]) == REQUIRED_COMMAND_ARG_COUNT.end())
    {
        m_out << "Unknown command: \"" << commands[0] << "\"\n";
        return;
    }
    if (REQUIRED_COMMAND_ARG_COUNT.at(commands[0]) != commands.size() - 1)
    {
        m_out << "Command \"" << commands[0] << "\" requires " << REQUIRED_COMMAND_ARG_COUNT.at(commands[0]) << " arguments \n"
            << "For more details, see \"help\"\n";
        return;
    }
    for (auto command : commands)
    {
        
    }
}