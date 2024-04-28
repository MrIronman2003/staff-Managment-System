#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>
#include "database.h"
#include "employee.h"
#include "validator.h"
#include "inputhandler.h"

using namespace std;
#define el "\n"

class Menu {
    Input_Handler user_input;
    Employee_Validator validate_input;
    Database employee_database;
    string input;
    Employee New_employee;
    address new_employee_addresss;
    vector<CompanyPosition> display_positions = validate_input.return_positions();
    string temp_street_name, temp_near_by_landmarks, temp_building_num, temp_floor_num, temp_apart_num;

    int validate_state = 0;

public:
    void display_menu() {
        system("cls");
        cout << "Staff Management System" << el << el;
        cout << "====================================================" << el;
        cout << "Main Menu\n"
            << "====================================================\n";
        cout << "1. Add New Employee.\n"
            << "2. Edit Employee data.\n"
            << "3. Search Employee.\n"
            << "4. Search Employee with high wage.\n"
            << "5. Delete Employee data.\n"
            << "6. Exit Program.\n";
        select_option();
    }
    void select_option() {
        int option;

        // Validate user input
        while (!(cin >> option) || option < 1 || option > 6) {
            cout << "Invalid choice. Please enter a valid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Switch case to handle different options
        switch (option) {
        case 1: {
            cout << "Add New Employee selected";
            execute_option(1);
            break;
        }
        case 2: {
            cout << "Edit Employee Data selected";
            execute_option(2);
            break;
        }
        case 3: {
            cout << "Search Employee selected";
            execute_option(3);
            break;
        }
        case 4: {
            cout << "Search Employee with High Wage selected";
            execute_option(4);
            break;
        }
        case 5: {
            cout << "Delete Employee Data selected";
            execute_option(5);
            break;
        }
        case 6: {
            execute_option(6);
        }
        }
    }
    void execute_option(int choice) {
        switch (choice) {
        case 1: {
            system("cls");
            cout << "Add new Employee Data selected";

            //Handle ID
            cout << el << "Enter ID or type \"exit\" to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                cin.ignore(); //clear buffer
                input = user_input.get_input();
                validate_state = validate_input.validate_id(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid ID or exit to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "ID is already taken, please enter a new ID!" << el;
                }
            }
            long long ID = stoll(input);

            //Handle Name
            cout << "Enter Employee Name or type \"exit\" to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_name(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid Name or exit to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "Name already exist, please enter a new Name!" << el;
                }
            }

            //Handle Age
            cout << "Enter Employee Age or type \"exit\" to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_age(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid Age or type exit to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "Age already exist, please enter a new Name!" << el;
                }
            }
            int age = stoi(input);

            //Handle Addresss
            cout << "Enter Employee Home Address or type \"exit\" to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state

                cout << "Enter street name: " << el;
                input = user_input.get_input();
                if (validate_input.validate_exit(input) == -1) {
                    display_menu();
                }
                temp_street_name = input;

                cout << "Enter near by land mark: " << el;
                input = user_input.get_input();
                temp_near_by_landmarks = input;

                cout << "Enter Building Number: " << el;
                input = user_input.get_input();
                if (validate_input.validate_exit(input) == -1) {
                    display_menu();
                }
                temp_building_num = input;

                cout << "Enter Floor Number: " << el;
                input = user_input.get_input();
                if (validate_input.validate_exit(input) == -1) {
                    display_menu();
                }
                temp_floor_num = input;

                cout << "Enter Apartment Number: " << el;
                input = user_input.get_input();
                if (validate_input.validate_exit(input) == -1) {
                    display_menu();
                }
                temp_apart_num = input;


                validate_state = validate_input.validate_home_address(temp_street_name, temp_near_by_landmarks, temp_building_num, temp_floor_num, temp_apart_num);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid address data or type exit to return to the main menu!" << el;
                }
                else if (validate_state == 0) {
                    break;
                }
            }

            // Handle Employee Role and display the positions in a table
            cout << "Enter Employee Role or type \"exit\" to return to the main menu!" << el;
            cout << "-----------------------------------------" << el;
            cout << "| Title                        | Abbreviation |" << el;
            cout << "-----------------------------------------" << el;
            for (const auto& pos : display_positions) {
                cout << "| " << left << setw(30) << pos.name << " | " << setw(12) << pos.abbreviation << " |" << el;
            }
            cout << "-----------------------------------------" << el;
            //Role Validation proccess
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_role(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid Role or type \"exit\" to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "Executive role is taken by another employee, please reneter your role, or type \"exit\" to return to the main menu!" << el;
                }
            }
            //save validated role
            string role = input;

            //Handle Employee Salary
            cout << "Enter Employee Salary or type \"exit\" to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_salary(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid salary or type \"exit\" to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "Executive role is taken by another employee, please reneter your role, or type \"exit\" to retunr to the main menu!" << el;
                }
            }
            float salary = stof(input);

            //saving Data to database class
            //save validated ID
            New_employee.set_id(ID); 
            //save validated Name
            New_employee.set_name(input); 
            //save validated age
            New_employee.set_age(age);
            //save validated Employee address
            new_employee_addresss.street_name = temp_street_name;
            new_employee_addresss.near_by_landmarks = temp_near_by_landmarks;
            new_employee_addresss.building_number = stoi(temp_building_num);
            new_employee_addresss.floor_number = stoi(temp_floor_num);
            new_employee_addresss.apartment_number = stoi(temp_apart_num);
            New_employee.set_home_address(new_employee_addresss);
            New_employee.set_role(role);
            New_employee.set_salary(salary);
            //Save data of employee in Database
            employee_database.add_employee(New_employee);

            //Confirmation to return to the main menu by pressing enter
            cout << "Employee data saved successfully!\n"
                "press enter to return to the menu.\n";
            string status;
            getline(cin, status);
            break;
        }
        case 2: {
            cout << "Edit Employee Data selected";
            execute_option(2);
            break;
        }
        case 3: {
            cout << "Search Employee selected";
            execute_option(3);
            break;
        }
        case 4: {
            cout << "Search Employee with High Wage selected";
            execute_option(4);
            break;
        }
        case 5: {
            cout << "Delete Employee Data selected";
            execute_option(5);
            break;
        }
        case 6: {
            exit_system();
            display_menu();
        }
        }

        //return to the main menu after option have been executed
        display_menu();
    }
    void exit_system() {
        // Clear the console and display the exit message
        system("cls");
        cout << "Staff Management Program\n\n";
        cout << "Are you sure you want to exit the program?\n"
            "1. No.\n"
            "2. Yes.\n";

        int option;

        // Validate the user's choice
        while (!(cin >> option) || option < 1 || option > 2) {
            cout << "Invalid choice. Please enter a valid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Switch case to handle the user's choice
        switch (option) {
        case 1: {
            // If the user chooses not to exit, return to the main menu
            break;
        }
        case 2: {
            // If the user chooses to exit, display the credits and exit the program
            cout << "Program made by:\n"
                "Mahmoud Ahmed\tID: 234051\n"
                "Ahmed Hussein\tID: 225381\n"
                "Exiting Program...\n";
            exit(1);
            break;
        }
        }
    }
};