#include "stdafx.h"
#include "..\Car\Car.h"
#include "..\Car\CarController.h"

struct CarControllerFixture
{
    CCar car;
};

// ����� CCarController
BOOST_FIXTURE_TEST_SUITE(CCarController_class, CarControllerFixture)

    // ������ ������� ���������� false
    BOOST_AUTO_TEST_CASE(empty_command_returns_false)
    {
        CCarController carController(car, std::cin, std::cout);
        BOOST_CHECK(!carController.HandleCommand({}));
    }

    // ��������� ������ �� ������� � �����������
    BOOST_AUTO_TEST_CASE(split_line_to_command_with_arguments)
    {
        std::vector<std::string> command;
        std::stringstream ss_in;
        ss_in << "command argv1 argv2";
        std::stringstream ss_out;
        CCarController carController(car, ss_in, ss_out);
        carController.GetCommand(command);
        BOOST_CHECK(command[0] == "command");
        BOOST_CHECK(command[1] == "argv1");
        BOOST_CHECK(command[2] == "argv2");
    }

    // ������������ ��������� �������
    BOOST_AUTO_TEST_CASE(handle_known_commands)
    {
        std::stringstream ss_in;
        std::stringstream ss_out;
        CCarController carController(car, ss_in, ss_out);
        BOOST_CHECK(carController.HandleCommand({ "help" }));
        BOOST_CHECK(carController.HandleCommand({ "exit" }));
        BOOST_CHECK(carController.HandleCommand({ "info" }));
        BOOST_CHECK(carController.HandleCommand({ "engineon" }));
        BOOST_CHECK(carController.HandleCommand({ "setgear", "-1" }));
        BOOST_CHECK(carController.HandleCommand({ "setspeed", "1" }));
        BOOST_CHECK(carController.HandleCommand({ "engineoff" }));
    }

    // ���������� false ��� ��������� ������������� ���������
    BOOST_AUTO_TEST_CASE(false_when_wrong_command)
    {
        std::stringstream ss_in;
        std::stringstream ss_out;
        CCarController carController(car, ss_in, ss_out);
        BOOST_CHECK(!carController.HandleCommand({ "unknown" }));
        BOOST_CHECK(!carController.HandleCommand({ "setgear" }));
        BOOST_CHECK(!carController.HandleCommand({ "setspeed" }));
        BOOST_CHECK(!carController.HandleCommand({ "setgear word" }));
        BOOST_CHECK(!carController.HandleCommand({ "setspeed word" }));
    }

BOOST_AUTO_TEST_SUITE_END()