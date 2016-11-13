#include "stdafx.h"
#include "Car.h"
#include "CarController.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    CCar granta;
    CCarController carController(granta, cin, cout);
    vector<string> command;

    while (carController.GetCommand(command))
    {
        carController.HandleCommand(command);
    }
    return EXIT_SUCCESS;
}