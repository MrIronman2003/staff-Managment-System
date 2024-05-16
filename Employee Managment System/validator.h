/*
    validator guide:
    -----------------------------------------------------------------
    -1 --> user entered exit
    0 --> validation passed succesfully
    1 --> invalid input, user entered wrong data or very large input
    2 --> duplicate data found
*/

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "main.h"
#include "database.h"
#include "employee.h"

struct CompanyPosition {
    string name;
    string abbreviation;
};

class Employee_Validator {
	int search_result = 0;
    Database search;
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
    vector<CompanyPosition> non_executive_positions = {
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
    vector<CompanyPosition> positions = {
        //Executive positions
        {"Chief Executive Officer", "CEO"},
        {"Chief Operating Officer", "COO"},
        {"Chief Financial Officer", "CFO"},
        {"Chief Marketing Officer", "CMO"},
        {"Chief Technology Officer", "CTO"},
        {"President", "President"},
        {"Vice President", "VP"},
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

public:
    //Validate Inputs
    int validate_id(const string& ID_check) {
        try {
            long long ID = stoll(ID_check);  // Convert input to long long
            if (ID < 0 || ID > 10000000000) {
                return 1;  // Invalid input (large number)
            }
            // Assuming `find_employee_by_id` exists in the `Database` class
            if (search.find_employee_by_id(ID) != -1) {
                return 2;  // ID found
            }
            return 0;  // No error
        }
        catch (const invalid_argument&) {
            if (check_exit(ID_check) == true) {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }
    int validate_name(string name_check) {
        if (check_exit(name_check) == true) {
            return -1;
        }
        else if (search.find_employee_by_name(name_check) != -1) {
            return 2;
        }
        else {
            return 0;
        }
    }
    int validate_age(const string& age_check) {
        try {
            int age = stoi(age_check);  // Convert input to integer
            if (age < 16 || age > 120) {
                return 1;  // Invalid input (outside valid range)
            }
            else {
                return 0;  // No error
            }
        }
        catch (const invalid_argument&) {
            if (check_exit(age_check) == true) {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }
    int validate_home_address(const string& check_street, const string& check_nearby_landmark,
        const string& check_building_number, const string& check_floor_num,
        const string& check_appart_num) {
        try {
            // Convert building number to an integer
            int building_number = stoi(check_building_number);

            // Convert floor number to an integer
            int floor_number = stoi(check_floor_num);

            // Convert apartment number to an integer
            int apartment_number = stoi(check_appart_num);

            return 0;  // No error
        }
        catch (const invalid_argument&) {
            if (check_exit(check_building_number) == true || check_exit(check_floor_num) == true || check_exit(check_appart_num) == true == true) {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }
    int validate_role(const string& role_check) {
        if (check_exit(role_check) == true) {
            return -1; // Return to main menu
        }

        // Convert user input to lowercase for case-insensitive comparison
        string lowercase_input = role_check;
        transform(lowercase_input.begin(), lowercase_input.end(), lowercase_input.begin(), ::tolower);

        for (const auto& position : positions) {
            // Convert both position name and abbreviation to lowercase for comparison
            string lowercase_position_name = position.name;
            string lowercase_position_abbreviation = position.abbreviation;
            transform(lowercase_position_name.begin(), lowercase_position_name.end(), lowercase_position_name.begin(), ::tolower);
            transform(lowercase_position_abbreviation.begin(), lowercase_position_abbreviation.end(), lowercase_position_abbreviation.begin(), ::tolower);

            if (lowercase_position_name == lowercase_input || lowercase_position_abbreviation == lowercase_input) {
                // Check if the role is an executive role
                for (const auto& executive_position : Executive_Positions) {
                    string lowercase_executive_position_name = executive_position.name;
                    string lowercase_executive_position_abbreviation = executive_position.abbreviation;
                    transform(lowercase_executive_position_name.begin(), lowercase_executive_position_name.end(), lowercase_executive_position_name.begin(), ::tolower);
                    transform(lowercase_executive_position_abbreviation.begin(), lowercase_executive_position_abbreviation.end(), lowercase_executive_position_abbreviation.begin(), ::tolower);

                    if (lowercase_executive_position_name == lowercase_input || lowercase_executive_position_abbreviation == lowercase_input) {
                        // Call find_employee_by_role and check if an employee exists
                        search_result = search.find_employee_by_role(role_check);
                        if (search_result != -1) {
                            return 2; //Role found
                        }

                    }
                }
                return 0; // Validation passed successfully
            }
        }
        return 1; // Return error
    }
    int validate_salary(string salary_check) {
        try {
            long long salary = stoll(salary_check);  // Convert input to long long
            if (salary < 0 || salary > 10000000) {
                return 1;  // Invalid input (large number)
            }
            // Assuming `find_employee_by_id` exists in the `Database` class
            return 0;  // No error
        }
        catch (const invalid_argument&) {
            if (check_exit(salary_check) == true) {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }

	//Validate specific roles
    int validate_executive_role(const string& role_check) {
        if (check_exit(role_check) == true) {
            return -1; // Return to main menu
        }

        // Convert user input to lowercase for case-insensitive comparison
        string lowercase_input = role_check;
        transform(lowercase_input.begin(), lowercase_input.end(), lowercase_input.begin(), ::tolower);

        for (const auto& executive_position : Executive_Positions) {
            // Convert both position name and abbreviation to lowercase for comparison
            string lowercase_executive_position_name = executive_position.name;
            string lowercase_executive_position_abbreviation = executive_position.abbreviation;
            transform(lowercase_executive_position_name.begin(), lowercase_executive_position_name.end(), lowercase_executive_position_name.begin(), ::tolower);
            transform(lowercase_executive_position_abbreviation.begin(), lowercase_executive_position_abbreviation.end(), lowercase_executive_position_abbreviation.begin(), ::tolower);

            if (lowercase_executive_position_name == lowercase_input || lowercase_executive_position_abbreviation == lowercase_input) {
                // Call find_employee_by_role and check if an employee exists
                search_result = search.find_employee_by_role(role_check);
                if (search_result != -1) {
                    return 2; //Role found
                }
                return 0; // Validation passed successfully
            }
        }
        return 1; // Return error
    }
    int validate_non_executive_role(const string& role_check) {
        if (check_exit(role_check) == true) {
            return -1; // Return to main menu
        }

        // Convert user input to lowercase for case-insensitive comparison
        string lowercase_input = role_check;
        transform(lowercase_input.begin(), lowercase_input.end(), lowercase_input.begin(), ::tolower);

        for (const auto& non_executive_position : non_executive_positions) {
            // Convert both position name and abbreviation to lowercase for comparison
            string lowercase_non_executive_position_name = non_executive_position.name;
            string lowercase_non_executive_position_abbreviation = non_executive_position.abbreviation;
            transform(lowercase_non_executive_position_name.begin(), lowercase_non_executive_position_name.end(), lowercase_non_executive_position_name.begin(), ::tolower);
            transform(lowercase_non_executive_position_abbreviation.begin(), lowercase_non_executive_position_abbreviation.end(), lowercase_non_executive_position_abbreviation.begin(), ::tolower);

            if (lowercase_non_executive_position_name == lowercase_input || lowercase_non_executive_position_abbreviation == lowercase_input) {
                // Call find_employee_by_role and check if an employee exists
                search_result = search.find_employee_by_role(role_check);
                if (search_result != -1) {
                    return 2; //Role found
                }
                return 0; // Validation passed successfully
            }
        }
        return 1; // Return error
    }

	//validate specific inputs
    int validate_int(string check_int) {
        try {
            long long input_to_int = stoll(check_int);  // Convert input to long long
            if (input_to_int < 0 || input_to_int > 1000000) {
                return 1;  // Invalid input (large number)
            }
            return 0;  // No error
        }
        catch (const invalid_argument&) {
            if (check_exit(check_int) == true) {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }
    bool check_exit(const string& input) {
        // Create a copy of the input string
        string lower_input = input;

        // Convert the copy to lower case
        transform(lower_input.begin(), lower_input.end(), lower_input.begin(), ::tolower);

        // Check if the lower case string is "exit"
        if (lower_input == "exit") {
            return true;
        }
        else {
            return false;
        }
    }
	bool highwage_stat(const vector<Employee>& employees) {
		// Check if the vector is empty
        if (employees.empty()) {
            return false;
        }
		else {
			return true;
		}
	}

	//Return positions for printing
    vector<CompanyPosition> return_positions() {
        return positions;
    }
};
#endif