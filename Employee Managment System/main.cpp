#include <iostream>
#include <string>
#include "staffmanagmentsystem.h"

using namespace std;
#define el "\n"

int main() {

    cout << "Staff Managment System starting up..." << el;
    cout << "program made by: " << el << "Mahmoud Ahmed \t ID: 234051" << el;
    cout << "Ahmed Hussein \t ID: 225381" << el;
    cout << "press enter to Launch the program." << el;
    string status;
    getline(cin, status);

    Staff_Managment_System system;
    system.run();

    return 0;
}