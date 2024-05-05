#include <iostream>
#include <string>
#include <limits>
#include "staffmanagmentsystem.h"

using namespace std;

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {

    // Clear the screen
    system("cls");

    // Use ASCII art for the title
    cout << RED << R"(
   _____ _         __  __ 
  / ____| |       / _|/ _|
 | (___ | |_ __ _| |_| |_ 
  \___ \| __/ _` |  _|  _|
  ____) | || (_| | | | |  
 |_____/ \__\__,_|_| |_|                                         
)" << RESET << el;

    cout << RED << R"(
  __  __                                              _   
 |  \/  |                                            | |  
 | \  / | __ _ _ __   __ _  __ _ _ __ ___   ___ _ __ | |_ 
 | |\/| |/ _` | '_ \ / _` |/ _` | '_ ` _ \ / _ \ '_ \| __|
 | |  | | (_| | | | | (_| | (_| | | | | | |  __/ | | | |_ 
 |_|  |_|\__,_|_| |_|\__,_|\__, |_| |_| |_|\___|_| |_|\__|
                            __/ |                         
                           |___/                          
)" << RESET << el;

    cout << RED << R"(
   _____           _                 
  / ____|         | |                
 | (___  _   _ ___| |_ ___ _ __ ___  
  \___ \| | | / __| __/ _ \ '_ ` _ \ 
  ____) | |_| \__ \ ||  __/ | | | | |
 |_____/ \__, |___/\__\___|_| |_| |_|
          __/ |                      
         |___/                                                              
)" << RESET << el;

    cout << "Program made by: " << "\n";
    cout << BLUE << "Mahmoud Ahmed \t ID: 234051" << RESET << "\n";
    cout << GREEN << "Ahmed Hussein \t ID: 225381" << RESET << "\n";
    cout << "Press enter to launch the program." << "\n";
    string status;
    getline(cin, status);

    Staff_Managment_System system;
    system.run();

    return 0;
}
