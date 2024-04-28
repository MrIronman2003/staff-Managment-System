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

#include <iostream>
#include <string>
#include <limits>
#include "database.h"
#include "employee.h"

using namespace std;
constexpr auto el = "\n";

struct CompanyPosition {
    string name;
    string abbreviation;
};

class Employee_Validator {
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
    int validate_id(const string& ID_check) {
        try {
            long long ID = stoll(ID_check);  // Convert input to long long
            if (ID > 10000000000) {
                return 1;  // Invalid input (large number)
            }
            // Assuming `find_employee_by_id` exists in the `Database` class
            if (search.find_employee_by_id(static_cast<int>(ID)) != -1) {
                return 2;  // ID found
            }
            return 0;  // No error
        }
        catch (const invalid_argument&) {
            if (ID_check == "exit") {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }

    int validate_name(string name_check) {

        if (name_check == "exit") {
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
            if (age_check == "exit") {
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

            // Check if the conversion was successful
            // (You can add additional validation logic here if needed)

            // Assuming other address validation checks (e.g., street, landmark) are performed elsewhere

            return 0;  // No error
        }
        catch (const invalid_argument&) {
            if (check_street == "exit" || check_nearby_landmark == "exit" ||
                check_building_number == "exit" || check_floor_num == "exit" || check_appart_num == "exit") {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }

    int validate_role(const string& role_check) {
        if (role_check == "exit") {
            return -1; // Return to main menu
        }

        // Convert user input to lowercase for case-insensitive comparison
        string lowercase_input = role_check;
        transform(lowercase_input.begin(), lowercase_input.end(), lowercase_input.begin(), ::tolower);

        for (const auto& position : Executive_Positions) {
            // Convert position name to lowercase for comparison
            string lowercase_position = position.name;
            transform(lowercase_position.begin(), lowercase_position.end(), lowercase_position.begin(), ::tolower);

            if (lowercase_position == lowercase_input) {
                return 0; // Validation passed successfully
            }
        }

        // Check if the role is an executive position
        for (const auto& position : Executive_Positions) {
            if (position.name == role_check) {
                // Call find_employee_by_role and check if an employee exists
                if (search.find_employee_by_role(role_check) != -1) {
                    return 2; // ID found
                }
            }
        }

        return 1; // Return error
    }


    int validate_salary(string salary_check) {

        try {
            long long ID = stoll(salary_check);  // Convert input to long long
            if (ID > 10000000000) {
                return 1;  // Invalid input (large number)
            }
            // Assuming `find_employee_by_id` exists in the `Database` class
            return 0;  // No error
        }
        catch (const invalid_argument&) {
            if (salary_check == "exit") {
                return -1;  // User entered "exit"
            }
            return 1;  // Invalid input
        }
        catch (const out_of_range&) {
            return 1;  // Invalid input (out of range)
        }
    }

    int validate_exit(string check_exit_state) {
        if (check_exit_state == "exit") {
            return -1;
        }
        else {
            return 0;
        }
    }
};
#endif