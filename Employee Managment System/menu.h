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

vector<Employee> Database::Employees_data;

class Menu {
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
			break;
        }
        }
    }
    void execute_option(int choice) {
        switch (choice) {
        //Add new employee
        case 1: {
            system("cls");
            cout << "Adding new Employee Data" << el;
			New_employee = collect_data();

			//saving new employee data in database
            employee_database.add_employee(New_employee);

            //Confirmation to return to the main menu by pressing enter
            cout << "Employee data saved successfully!\n"
                "press enter to return to the menu.\n";
            string status;
            getline(cin, status);
            break;
        }

        //Edit Employee Data 
        case 2: {
            system("cls");
            cout << "Editing Employee Data: " << el;

            //look for the ID to edit
            cout << "Enter employee ID you want to edit or tpye \"exit\" to return to the main menu" << el;
            cin.ignore();
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_id(input);
                if (validate_state == 0) {
                    cout << "ID not found, please enter a valid id or type \"exit\" to return to the main menu" << el;
                }
                else if (validate_state == -1) {
                    display_menu();
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
			system("cls");
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
                system("cls");
				cout << "Editing Employee ID" << el;
				cout << "Enter new ID or type \"exit\" to return to the main menu" << el;
				cin.ignore();
                while (1) {
                    validate_state = 0; //reset validate_state
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
				employee_database.set_new_ID(ID, index);
                break;
            }

			//Edit Employee Name
            case 2: {
                system("cls");
				cout << "Editing Employee Name" << el;
				cout << "Enter new Name or type \"exit\" to return to the main menu" << el;
				cin.ignore();
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
				string name = input;
                employee_database.set_new_name(name, index);
                break;
            }

			//Edit Employee Age
            case 3: {
                system("cls");
				cout << "Editing Employee Age" << el;
				cout << "Enter new Age or type \"exit\" to return to the main menu" << el;
				cin.ignore();
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
                break;
            }

			//Edit Employee Address
            case 4: {
                system("cls");
				cout << "Editing Employee Address" << el;
				cout << "Enter new Address or type \"exit\" to return to the main menu" << el;
				cin.ignore();
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
                    while (true) {
                        input = user_input.get_input();
                        if (validate_input.validate_exit(input) == -1) {
                            display_menu();
                        }
                        else if (validate_input.validate_int(input) == 1) {
                            cout << "invalid input, please enter a valid number!" << el;
                        }
                        else {
                            break;
                        }
                    }
                    temp_building_num = input;

                    cout << "Enter Floor Number: " << el;
                    while (true) {
                        input = user_input.get_input();
                        if (validate_input.validate_exit(input) == -1) {
                            display_menu();
                        }
                        else if (validate_input.validate_int(input) == 1) {
                            cout << "invalid input, please enter a valid number!" << el;
                        }
                        else {
                            break;
                        }
                    }
                    temp_floor_num = input;

                    cout << "Enter Apartment Number: " << el;
                    while (true) {
                        input = user_input.get_input();
                        if (validate_input.validate_exit(input) == -1) {
                            display_menu();
                        }
                        else if (validate_input.validate_int(input) == 1) {
                            cout << "invalid input, please enter a valid number!" << el;
                        }
                        else {
                            break;
                        }
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
                edit_employee_addresss.street_name = temp_street_name;
                edit_employee_addresss.near_by_landmarks = temp_near_by_landmarks;
                edit_employee_addresss.building_number = stoi(temp_building_num);
                edit_employee_addresss.floor_number = stoi(temp_floor_num);
                edit_employee_addresss.apartment_number = stoi(temp_apart_num);
				employee_database.set_new_address(edit_employee_addresss, index);
                break;
            }

			//Edit Employee Role
            case 5: {
				system("cls");
				cout << "Editing Employee Role" << el;
				cout << "Enter new Role or type \"exit\" to return to the main menu" << el;
				cin.ignore();
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
				string role = input;
				employee_database.set_new_role(role, index);
                break;
            }

			//Edit Employee Salary
            case 6: {
				system("cls");
				cout << "Editing Employee Salary" << el;
				cout << "Enter new Salary or type \"exit\" to return to the main menu" << el;
				cin.ignore();
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
				employee_database.set_new_salary(salary, index);
                break;
            }

			//Edit All Employee Info
            case 7: {
				system("cls");
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
                break;
            }
			}
		}

        case 3: {
            cout << "Search Employee selected";
            break;
        }

        case 4: {
            cout << "Search Employee with High Wage selected";
            break;
        }

        case 5: {
            cout << "Delete Employee Data selected";
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

    Employee collect_data() {
        //Handle ID
        cout << "Enter ID or type \"exit\" to return to the main menu!" << el;
        cin.ignore(); //clear buffer
        while (1) {
            validate_state = 0; //reset validate_state
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
        string name = input;

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
            while (true) {
                input = user_input.get_input();
                if (validate_input.validate_exit(input) == -1) {
                    display_menu();
                }
                else if (validate_input.validate_int(input) == 1) {
                    cout << "invalid input, please enter a valid number!" << el;
                }
                else {
                    break;
                }
            }
            temp_building_num = input;

            cout << "Enter Floor Number: " << el;
            while (true) {
                input = user_input.get_input();
                if (validate_input.validate_exit(input) == -1) {
                    display_menu();
                }
                else if (validate_input.validate_int(input) == 1) {
                    cout << "invalid input, please enter a valid number!" << el;
                }
                else {
                    break;
                }
            }
            temp_floor_num = input;

            cout << "Enter Apartment Number: " << el;
            while (true) {
                input = user_input.get_input();
                if (validate_input.validate_exit(input) == -1) {
                    display_menu();
                }
                else if (validate_input.validate_int(input) == 1) {
                    cout << "invalid input, please enter a valid number!" << el;
                }
                else {
                    break;
                }
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

        //save validated ID
        collected_data.set_id(ID);
        //save validated Name
        collected_data.set_name(name);
        //save validated age
        collected_data.set_age(age);
        //save validated Employee address
        collected_data_address.street_name = temp_street_name;
        collected_data_address.near_by_landmarks = temp_near_by_landmarks;
        collected_data_address.building_number = stoi(temp_building_num);
        collected_data_address.floor_number = stoi(temp_floor_num);
        collected_data_address.apartment_number = stoi(temp_apart_num);
        collected_data.set_home_address(new_employee_addresss);
		//saving validated role
        collected_data.set_role(role);
		//saving validated salary
        collected_data.set_salary(salary);

		return collected_data;
    }


};