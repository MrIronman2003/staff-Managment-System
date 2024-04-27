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

class Employee_Validator {
    Database search;
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

    int validate_age(string age_check) {
        try {
            int age = stoll(age_check);  // Convert input to long long
            if (age > 1000) {
                return 1;  // Invalid input (large number)
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

    int validate_home_address(address address_check) {

    }

    int validate_role(string role_check) {

    }

    int validate_salary(string salary_check) {

    }
};
#endif