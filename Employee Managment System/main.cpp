#include "main.h"
#include "staffmanagmentsystem.h"

int main() {

    // Clear the screen
    system(CLEAR);

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

    cout << R"(
The Staff Management Program is a program designed to streamline the process of managing staff data.
This simple yet robust program allows users to input, edit, and delete employee information with ease.

One of the key features of this program is its ability to save data in both .txt and .csv formats.
This ensures that users can access and manipulate the data outside the program, providing an additional layer of convenience.

Understanding that users may sometimes forget to save their latest data, the program includes an auto-save feature.
When exiting the program via the main menu, the most recent data is automatically saved to the external files, ensuring no information is lost.

Designed with user experience in mind, the program is capable of handling multiple errors without crashing, providing a smooth and uninterrupted experience.

The program also includes a powerful search feature. This allows users to locate employees using their full name stored in the system.
Additionally, users can utilize this feature to identify who currently holds a specific executive role.
)" << el;

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
