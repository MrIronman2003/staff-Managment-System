#ifndef MENU_H
#define MENU_H

#include "main.h"
#include "outputhandler.h"
#include "database.h"
#include "employee.h"
#include "validator.h"
#include "inputhandler.h"
#include "filehandler.h"

vector<Employee> Database::Employees_data;

class Menu : public Out_Put_Handler {

protected:    
    Input_Handler user_input;
    Employee_Validator validate_input;
    Database employee_database;
    Employee New_employee, collected_data, Edited_employee;

    //Addresss
    address new_employee_addresss, edit_employee_addresss, collected_data_address;

    //temp variables
    string temp_street_name, temp_near_by_landmarks, temp_building_num, temp_floor_num, temp_apart_num, input;

    //vectors
    vector<CompanyPosition> display_positions = validate_input.return_positions();
    vector<CompanyPosition> Executive_Positions = {
        //Executive positions
        {"Chief Executive Officer", "CEO"},
        {"Chief Operating Officer", "COO"},
        {"Chief Financial Officer", "CFO"},
        {"Chief Marketing Officer", "CMO"},
        {"Chief Technology Officer", "CTO"},
        {"President", "President"},
        {"Vice President", "VP"}
    };
    vector<CompanyPosition> positions_managment_operational = {
        //Managment positions
        {"General Manager", "GM"},
        {"Operaation Manager", "OM"},
        {"Human Resource Manger", "HR"},
        {"Marketing Manager", "MM"},
        {"Finance Manager", "FM"},
        {"Information Technology Manager", "IT"},
        {"Project Manager", "PM"},
        //Operational positions
        {"Sales Representative", "SR"},
        {"Customer Service Representative", "CSR"},
        {"Administrative Assistant", "AA"},
        {"Data Analyst", "DA"},
        {"Quality Control Inspector", "QCI"},
        {"Production Worker", "PW"}
    };

    int validate_state = 0;

public:
    void select_option() {
        int option;
        // Validate user input
        while (!(cin >> option) || option < 1 || option > 7) {
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
            break;
        }
        case 7: {
            execute_option(7);
            break; }
        }
    }
    void execute_option(int choice) {
        switch (choice) {
            //Add new employee
        case 1: {
            system(CLEAR);
            cin.ignore();
            cout << "Adding new Employee Data" << el;
            New_employee = collect_data();

            cout << "Employee Data " << el;
            display_employee_for_save(New_employee);
            cout << "Are you sure you want to save this data?" << el;
            cout << GREEN << "Yes" << el;
            cout << RED << "No" << RESET << el;

            string option;
            while (true) {
                getline(cin, option);
                transform(option.begin(), option.end(), option.begin(), ::tolower); // convert to lowercase

                if (option == "y" || option == "yes") {
                    //saving new employee data in database
                    employee_database.add_employee(New_employee);

                    //Confirmation to return to the main menu by pressing enter
                    cout << "Employee data saved successfully!" << el << "press enter to return to the menu." << el;
                    string status;
                    getline(cin, status);
                    break;
                }
                else if (option == "n" || option == "no") {
                    break;
                }
                else {
                    cout << "Invalid choice. Please enter Y/N or Yes/No.\n";
                }
            }
            break;
        }

              //Edit Employee Data 
        case 2: {
            system(CLEAR);
            cout << "Editing Employee Data: " << el;

            //look for the ID to edit
            cin.ignore();
            cout << "Enter employee ID you want to edit or tpye \"exit\" to return to the main menu" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_id(input);
                if (validate_state == 0) {
                    cout << "ID not found, please enter a valid id or type \"exit\" to return to the main menu" << el;
                }
                else if (validate_state == -1) {
                    display_menu();
                    select_option();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid ID or exit to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "ID Found!" << el;
                    break;
                }
            }

            //get employee index
            int index = employee_database.find_employee_by_id(stoll(input));

            //display edit options
            system(CLEAR);
            cout << "what do you want to edit?" << el;
            cout << "1. ID" << el;
            cout << "2. Name" << el;
            cout << "3. Age" << el;
            cout << "4. Address" << el;
            cout << "5. Role" << el;
            cout << "6. Salary" << el;
            cout << "7. All info" << el;
            cout << "8. Return to main menu" << el;

            int edit_option;

            while (!(cin >> edit_option) || edit_option < 1 || edit_option > 8) {
                cout << "Invalid choice. Please enter a valid input.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (edit_option) {

                //Edit Employee ID
            case 1: {
                system(CLEAR);
                cin.ignore();
                cout << "Editing Employee ID" << el;
                long long ID = collect_ID();
                employee_database.set_new_ID(ID, index);
                break;
            }

                  //Edit Employee Name
            case 2: {
                system(CLEAR);
                cin.ignore();
                cout << "Editing Employee Name" << el;
                string name = collect_name();
                employee_database.set_new_name(name, index);
                break;
            }

                  //Edit Employee Age
            case 3: {
                system(CLEAR);
                cin.ignore();
                cout << "Editing Employee Age" << el;
                int age = collect_age();
                employee_database.set_new_age(age, index);
                break;
            }

                  //Edit Employee Address
            case 4: {
                system(CLEAR);
                cin.ignore();
                cout << "Editing Employee Address" << el;
                address new_employee_addresss = collect_address();
                employee_database.set_new_address(new_employee_addresss, index);
                break;
            }

                  //Edit Employee Role
            case 5: {
                system(CLEAR);
                cin.ignore();
                cout << "Editing Employee Role" << el;
                string role = collect_role();
                employee_database.set_new_role(role, index);
                break;
            }

                  //Edit Employee Salary
            case 6: {
                system(CLEAR);
                cin.ignore();
                cout << "Editing Employee Salary" << el;
                float salary = collect_salary();
                employee_database.set_new_salary(salary, index);
                break;
            }

                  //Edit All Employee Info
            case 7: {
                system(CLEAR);
                cin.ignore();
                cout << "Editing All Employee Info" << el;
                //getting edited employee data
                Edited_employee = collect_data();
                //sending edited data to database to be saved
                employee_database.set_new_ID(Edited_employee.get_id(), index);
                employee_database.set_new_name(Edited_employee.get_name(), index);
                employee_database.set_new_age(Edited_employee.get_age(), index);
                employee_database.set_new_address(Edited_employee.get_home_address(), index);
                employee_database.set_new_role(Edited_employee.get_role(), index);
                employee_database.set_new_salary(Edited_employee.get_salary(), index);
                break;
            }

                  //Return to main menu                  
            case 8: {
                display_menu();
                select_option();
                break;
            }
            }
            break;
        }

              //search employee
        case 3: {
            system(CLEAR);
            cout << "Searching Employee data" << el;
            cout << "Search Employee by: " << el;
            cout << "1. ID" << el;
            cout << "2. Name" << el;
            cout << "3. Role \"executive role ONLY\" " << el;
            cout << "4. Return to main menu" << el;

            int search_option;
            while (!(cin >> search_option) || search_option < 1 || search_option > 4) {
                cout << "Invalid choice. Please enter a valid input." << el;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (search_option) {

                //search employee by ID
            case 1: {
                system(CLEAR);
                cin.ignore();
                cout << "Enter employee ID you want to search or tpye \"exit\" to return to the main menu" << el;
                while (true) {
                    validate_state = 0; //reset validate_state
                    input = user_input.get_input();
                    validate_state = validate_input.validate_id(input);
                    if (validate_state == 0) {
                        cout << "ID not found, please enter a valid id or type \"exit\" to return to the main menu" << el;
                    }
                    else if (validate_state == -1) {
                        display_menu();
                        select_option();
                    }
                    else if (validate_state == 1) {
                        cout << "Invalid input, please enter a valid ID or exit to return to the main menu!" << el;
                    }
                    else if (validate_state == 2) {
                        break;
                    }
                }
                int index = employee_database.find_employee_by_id(stoll(input));
                display_employee_details(index);
                cout << "press enter to return to the menu." << el;
                string status;
                getline(cin, status);
                break;

            }

                  //search employee by Name
            case 2: {
                system(CLEAR);
                cin.ignore();
                cout << "Enter employee Name you want to search or tpye \"exit\" to return to the main menu" << el;
                while (true) {
                    validate_state = 0; //reset validate_state
                    input = user_input.get_input();
                    validate_state = validate_input.validate_name(input);
                    if (validate_state == 0) {
                        cout << "Name not found, please enter a valid name or type \"exit\" to return to the main menu" << el;
                    }
                    else if (validate_state == -1) {
                        display_menu();
                        select_option();
                    }
                    else if (validate_state == 1) {
                        cout << "Invalid input, please enter a valid Name or type \"exit\" to return to the main menu!" << el;
                    }
                    else if (validate_state == 2) {
                        cout << "Name have been found!" << el;
                        break;
                    }
                }
                int index = employee_database.find_employee_by_name(input);
                display_employee_details(index);
                cout << "press enter to return to the menu." << el;
                string status;
                getline(cin, status);
                break;
            }

                  //search employee by Role
            case 3: {
                system(CLEAR);
                cin.ignore();
                cout << "---------------------------------------------------" << el;
                cout << "| Title                            | Abbreviation |" << el;
                cout << "---------------------------------------------------" << el;

                // Display Executive Positions
                cout << "Executive Roles:" << el;
                for (const auto& pos : Executive_Positions) {
                    cout << "| " << left << setw(32) << pos.name << " | " << setw(12) << pos.abbreviation << " |" << el;
                }
                cout << "---------------------------------------------------" << el;
                cout << "Enter employee role you want to search or type \"exit\" to return to the main menu" << el;
                while (true) {
                    validate_state = 0; //reset validate_state
                    input = user_input.get_input();

                    // First, check if the role is a non-executive role
                    validate_state = validate_input.validate_non_executive_role(input);
                    if (validate_state == 0) {
                        cout << "Role entered is a non-executive role, please enter an executive role or type \"exit\" to return to the main menu" << el;
                        continue;
                    }

                    // Then, check if the role is an executive role
                    validate_state = validate_input.validate_executive_role(input);
                    if (validate_state == 0) {
                        cout << "Role not found, please enter a valid executive role or type \"exit\" to return to the main menu" << el;
                    }
                    else if (validate_state == -1) {
                        display_menu();
                        select_option();
                    }
                    else if (validate_state == 1) {
                        cout << "Invalid input, please enter a valid executive role or type \"exit\" to return to the main menu!" << el;
                    }
                    else if (validate_state == 2) {
                        cout << "Role has been found!" << el;
                        break;
                    }
                }
                cout << validate_state << el;
                cout << input << el;
                int index = employee_database.find_employee_by_role(input);
                display_employee_details(index);
                cout << "Press enter to return to the menu." << el;
                string status;
                getline(cin, status);
                break;
            }

                  //return to main menu
            case 4: {
                display_menu();
                select_option();
                break;
            }
            }

            break;

        }

              //search employee with high wage
        case 4: {
            cout << "Searching Employee with High Wage" << el;
            vector<Employee> high_wage_employees = employee_database.find_employees_with_high_wage();
            validate_state = validate_input.highwage_stat(high_wage_employees);
            if (validate_state == 1) {
                display_employee_details(high_wage_employees);
            }
            else if (validate_state == 0) {
                cout << "No employee with high wage found!" << el;
            }
            cout << "press enter to return to the menu." << el;
            string status;
            cin.ignore();
            getline(cin, status);


            break;
        }

              //delete employee data
        case 5: {
            system(CLEAR);
            cin.ignore();
            cout << "Deleting Employee data" << el;
            cout << "Enter employee ID you want to delete or type \"exit\" to return to the main menu" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_id(input);
                if (validate_state == 0) {
                    cout << RED << "ID not found, please enter a valid id or type \"exit\" to return to the main menu" << RESET << el;
                }
                else if (validate_state == -1) {
                    display_menu();
                    select_option();
                }
                else if (validate_state == 1) {
                    cout << RED << "Invalid input, please enter a valid ID or exit to return to the main menu!" << RESET << el;
                }
                else if (validate_state == 2) {
                    break;
                }
            }
            system(CLEAR);
            //get index of employee to be deleted
            int index = employee_database.find_employee_by_id(stoll(input));
            //print employee data to be deleted
            display_employee_details(index);

            //confirmation to delete employee data
            cout << "Are you sure you want to delete employee with id: " << input << "?" << el;
            cout << RED << "Warning: This action CANNOT be reverted!" << RESET << el;
            string option;
            cout << "Yes" << el << "No" << el;
            while (true) {
                getline(cin, option);
                transform(option.begin(), option.end(), option.begin(), ::tolower); // convert to lowercase

                if (option == "y" || option == "yes") {
                    employee_database.delete_employee(employee_database.find_employee_by_id(stoll(input)));
                    cout << "Employee data deleted successfully!" << el << "press enter to return to the menu." << el;
                    string status;
                    getline(cin, status);
                    break;
                }
                else if (option == "n" || option == "no") {
                    display_menu();
                    select_option();
                    break;
                }
                else {
                    cout << "Invalid choice. Please enter Y/N or Yes/No.\n";
                }
            }
            break;
        }

			  //save employee data to external files
		case 6: {
            system(CLEAR);
            cout << "Are you sure you want to save employee data to external files?" << el;
            cout << GREEN << "Yes" << el;
            cout << RED << "No" << RESET << el;
            string option;
			cin.ignore();
            while (true) {
                getline(cin, option);
                transform(option.begin(), option.end(), option.begin(), ::tolower);

                if (option == "y" || option == "yes") {
                    employee_database.save_data_to_file();
                    employee_database.save_data_to_excel();
                    cout << "Employee data saved to external files successfully!" << el << "press enter to return to the menu." << el;
                    string status;
                    getline(cin, status);
                    break;
                }
                else if (option == "n" || option == "no") {
                    display_menu();
                    select_option();
                    break;
                }
                else {
                    cout << "Invalid choice. Please enter Y/N or Yes/No.\n";
                }
            }
            break;
        }

              //exit program
        case 7: {
            exit_system();
            display_menu();
            select_option();
        }
        }

        //return to the main menu after option have been executed
        display_menu();
        select_option();
    }
    void exit_system() {
        // Clear the console and display the exit message
        system(CLEAR);
        cout << "Staff Management Program" << el << el;
        cout << "Are you sure you want to exit the program?" << el << RED << "Yes" << el << GREEN << "No" << RESET << el;

        string option;

        // Validate the user's choice
        while (true) {
            cin >> option;
            transform(option.begin(), option.end(), option.begin(), ::tolower); // Convert to lowercase

            if (option == "y" || option == "yes" || option == "n" || option == "no") {
                break;
            }
            else {
                cout << "Invalid choice. Please enter a valid input." << el;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // Switch case to handle the user's choice
        if (option == "n" || option == "no") {
            // If the user chooses not to exit, return to the main menu
            return;
        }
        else if (option == "y" || option == "yes") {
            // If the user chooses to exit, display the credits and exit the program
            employee_database.save_data_to_file();
            employee_database.save_data_to_excel();
            system(CLEAR);
            cout << "Program made by:" << el << "Mahmoud Ahmed\tID: 234051" << el << "Ahmed Hussein\tID: 225381" << el << el << "press enter to exit the program" << el;
            string status;
            cin.ignore();
            getline(cin, status);
            exit(1);
        }
    }

    //collect employee data
    Employee collect_data() {
        Employee collected_data;
        collected_data.set_id(collect_ID());
        collected_data.set_name(collect_name());
        collected_data.set_age(collect_age());
        collected_data.set_home_address(collect_address());
        collected_data.set_role(collect_role());
        collected_data.set_salary(collect_salary());
        return collected_data;
    }
    //collect and validate ID
    long long collect_ID() {
        cout << "Enter ID or type \"exit\" to return to the main menu!" << el;
        while (1) {
            validate_state = 0; //reset validate_state
            input = user_input.get_input();
            validate_state = validate_input.validate_id(input);
            if (validate_state == 0) {
                break;
            }
            else if (validate_state == -1) {
                display_menu();
                select_option();
            }
            else if (validate_state == 1) {
                cout << RED << "Invalid input, please enter a valid ID or exit to return to the main menu!" << RESET << el;
            }
            else if (validate_state == 2) {
                cout << RED << "ID is already taken, please enter a new ID!" << RESET << el;
            }
        }
        long long ID = stoll(input);
        return ID;
    }
    //collect and validate Name
    string collect_name() {
        cout << "Enter Employee Name or type \"exit\" to return to the main menu!" << el;
        while (1) {
            validate_state = 0; //reset validate_state
            input = user_input.get_input();

            // Check if the input is empty
            if (input.empty()) {
                cout << RED << "Input cannot be empty, please enter a Name!" << RESET << el;
                continue;
            }

            validate_state = validate_input.validate_name(input);
            if (validate_state == 0) {
                break;
            }
            else if (validate_state == -1) {
                display_menu();
                select_option();
            }
            else if (validate_state == 2) {
                cout << RED << "Name already exist, please enter a new Name!" << RESET << el;
            }
        }
        string name = input;
        return name;
    }
    //collect and validate Age
    int collect_age() {
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
                select_option();
            }
            else if (validate_state == 1) {
                cout << RED << "Invalid input, please enter a valid Age or type exit to return to the main menu!" << RESET << el;
            }
            else if (validate_state == 2) {
                cout << RED << "Age already exist, please enter a new Name!" << RESET << el;
            }
        }
        int age = stoi(input);
        return age;
    }
    //collect and validate Address
    address collect_address() {
        address collected_data_address;
        string temp_street_name, temp_near_by_landmarks, temp_building_num, temp_floor_num, temp_apart_num;
        int validate_state = 0;
        string input;

        cout << "Enter Employee Home Address or type \"exit\" to return to the main menu!" << el;

        temp_street_name = get_input("Enter street name: ");
        temp_near_by_landmarks = get_input("Enter near by land mark: ");
        temp_building_num = get_input("Enter Building Number: ", true);
        temp_floor_num = get_input("Enter Floor Number: ", true);
        temp_apart_num = get_input("Enter Apartment Number: ", true);

        validate_state = validate_input.validate_home_address(temp_street_name, temp_near_by_landmarks, temp_building_num, temp_floor_num, temp_apart_num);
        if (validate_state == 1) {
            cout << RED << "Invalid input, please enter a valid address data or type exit to return to the main menu!" << RESET << el;
        }

        collected_data_address.street_name = temp_street_name;
        collected_data_address.near_by_landmarks = temp_near_by_landmarks;
        collected_data_address.building_number = stoi(temp_building_num);
        collected_data_address.floor_number = stoi(temp_floor_num);
        collected_data_address.apartment_number = stoi(temp_apart_num);

        return collected_data_address;
    }
    //gets inputs for address
    string get_input(string prompt, bool isNumber = false) {
        string input;
        cout << prompt << el;
        while (true) {
            input = user_input.get_input();

            if (input.empty()) {
                cout << RED << "Input cannot be empty, please enter again!" << RESET << el;
                continue;
            }

            if (validate_input.check_exit(input)) {
                display_menu();
                select_option();
            }

            if (isNumber && validate_input.validate_int(input) == 1) {
                cout << RED << "Invalid input, please enter a valid number!" << RESET << el;
                continue;
            }

            break;
        }
        return input;
    }
    //collect and validate Role
    string collect_role() {
        //display the positions in a table
        cout << "---------------------------------------------------" << el;
        cout << "| Title                            | Abbreviation |" << el;
        cout << "---------------------------------------------------" << el;
        // Display Executive Positions
        cout << "Executive Roles:" << el;
        for (const auto& pos : Executive_Positions) {
            cout << "| " << left << setw(32) << pos.name << " | " << setw(12) << pos.abbreviation << " |" << el;
        }
        cout << "---------------------------------------------------" << el;
        // Display Management and Operational Positions
        cout << "Management and Operational Roles:" << el;
        for (const auto& pos : positions_managment_operational) {
            cout << "| " << left << setw(32) << pos.name << " | " << setw(12) << pos.abbreviation << " |" << el;
        }
        cout << "---------------------------------------------------" << el;
        cout << "Enter Employee Role Abbreviation or type \"exit\" to return to the main menu!" << el;
        //Role Validation proccess
        while (1) {
            validate_state = 0; //reset validate_state
            input = user_input.get_input();
            validate_state = validate_input.validate_role(input);

            // Check if the input is empty
            if (input.empty()) {
                cout << RED << "Input cannot be empty, please enter a valid role!" << RESET << el;
                continue;
            }

            if (validate_state == 0) {
                break;
            }
            else if (validate_state == -1) {
                display_menu();
                select_option();
            }
            else if (validate_state == 1) {
                cout << RED << "Invalid input, please enter a valid Role or type \"exit\" to return to the main menu!" << RESET << el;
            }
            else if (validate_state == 2) {
                cout << RED << "Executive role is taken by another employee, please reneter your role, or type \"exit\" to return to the main menu!" << RESET << el;
            }
        }
        //save validated role
        string role = input;
        transform(role.begin(), role.end(), role.begin(), ::toupper);
        return role;
    }
    //collect and validate Salary
    float collect_salary() {
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
                select_option();
            }
            else if (validate_state == 1) {
                cout << RED << "Invalid input, please enter a valid salary or type \"exit\" to return to the main menu!" << RESET << el;
            }
            else if (validate_state == 2) {
                cout << RED << "Executive role is taken by another employee, please reneter your role, or type \"exit\" to retunr to the main menu!" << RESET << el;
            }
        }
        float salary = stof(input);
        return salary;
    }
};
#endif