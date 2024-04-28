#ifndef DATABASE_H
#define DATABASE_H

// Include necessary libraries
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "employee.h"

// Use the standard namespace
using namespace std;

// Define the Database class
class Database
{
protected:
    vector<Employee> Employees_data;
public:
    //Setting 
    void add_employee(Employee new_Employee) {
        Employees_data.push_back(new_Employee);
    }

    int find_employee_by_id(int search_id) {
        for (int i = 0; i < Employees_data.size(); i++) {
            if (Employees_data[i].get_id() == search_id) {
                return i; // return the index of the Employee object
            }
        }
        return -1; // return -1 if no employee found
    }

    int find_employee_by_name(string search_name) {
        for (int i = 0; i < Employees_data.size(); i++) {
            if (Employees_data[i].get_name() == search_name) {
                return i; // return the index of the Employee object
            }
        }
        return -1; // return -1 if no employee found
    }

    void edit_employee_details(int id) {
        string new_name; // Initialize with the updated name
        string new_role; // Initialize with the updated role
        int new_age; // Initialize with the updated age
        float new_salary; // Initialize with the updated salary
        address new_home_address; // Initialize with the updated home address

        int index = find_employee_by_id(id);
        if (index != -1) {
            // Update employee data
            Employees_data[index].set_name(new_name);
            Employees_data[index].set_age(new_age);
            Employees_data[index].set_home_address(new_home_address);
            Employees_data[index].set_role(new_role);
            Employees_data[index].set_salary(new_salary);
        }
    }


    void delete_employee(int id) {
        int index = find_employee_by_id(id);
        if (index != -1) {
            Employees_data.erase(Employees_data.begin() + index);
        }
    }

    int find_employees_with_high_wage() {
        for (int i = 0; i < Employees_data.size(); i++) {
            if (Employees_data[i].get_salary() >= 20000) {
                return i; // return the index of the Employee object
            }
        }
        return -1; // return -1 if no employee with salary higher than 20,000 found
    }

    int find_employee_by_role(string search_role) {
        for (int i = 0; i < Employees_data.size(); i++) {
            if (Employees_data[i].get_role() == search_role) {
                return i; // return the index of the Employee object
            }
        }
        return -1; // return -1 if no employee with executive position where found

    }

    Employee retrive_data(int index) {

        return Employees_data[index];
    }
};
#endif