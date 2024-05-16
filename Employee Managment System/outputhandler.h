#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include "main.h"
#include "database.h"
#include "employee.h"
#include "validator.h"
#include "SalaryCalculator.h"
#include "inputhandler.h"

class Out_Put_Handler {
    Database data;
    Employee display_employee_data;
    address display_address_data;
    SalaryCalculator salary_calculator;
public:
    void display_menu() {
        system(CLEAR);
        cout << "Staff Management System" << el << el;
        cout << "====================================================" << el;
        cout << YELLOW << "\t\t   Main Menu" << RESET << el;
        cout << "====================================================" << el;
        cout << GREEN << "1. Add New Employee." << RESET << el;
        cout << BLUE << "2. Edit Employee data." << RESET << el;
        cout << CYAN << "3. Search Employee. " << RESET << el;
        cout << MAGENTA << "4. Search Employee with high wage. (20,000 per month or higher) " << RESET << el;
        cout << RED << "5. Delete Employee data." << RESET << el;
		cout << GREEN << "6. Save Employee data to external files." << RESET << el;
        cout << RED << "7. Exit Program." << RESET << el;
    }

    // Display employee(s) details
    void display_employee_details(int index) {
        system(CLEAR);

        // Retrieve the employee data using the provided index
        display_employee_data = data.retrive_data(index);

        // Retrieve the address data from the employee data
        display_address_data = display_employee_data.get_home_address();

        // Print the employee details in a table-like structure with lines separating each information
        cout << "----------------------------------------" << el;
        cout << left << setw(20) << "ID:" << display_employee_data.get_id() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Name:" << display_employee_data.get_name() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Age:" << display_employee_data.get_age() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Street:" << display_address_data.street_name << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Nearby landmarks:" << display_address_data.near_by_landmarks << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Building Number:" << display_address_data.building_number << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Floor Number:" << display_address_data.floor_number << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Apartment Number:" << display_address_data.apartment_number << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Role:" << display_employee_data.get_role() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Salary:" << fixed << setprecision(2) << display_employee_data.get_salary() << el << "----------------------------------------" << el;
        salary_calculator.set_salary(display_employee_data.get_salary());
        cout << left << setw(20) << "Yearly Salary:" << fixed << setprecision(2) << salary_calculator.calculate_salary() << el << "----------------------------------------" << el;
    }
    void display_employee_details(vector<Employee> employees) {
        system(CLEAR);
        cout << "----------------------------------------" << el;
        // Loop through the employees vector and print the details of each employee
        for (int i = 0; i < employees.size(); i++) {
            // Print the title for each employee
            cout << "Employee " << (i + 1) << el;
            cout << "------------------" << el;

            // Print the employee details in a table-like structure
            cout << left << setw(20) << "ID:" << employees[i].get_id() << el;
            cout << "----------------------------------------" << el;
            cout << left << setw(20) << "Name:" << employees[i].get_name() << el;
            cout << "----------------------------------------" << el;
            cout << left << setw(20) << "Age:" << employees[i].get_age() << el;
            cout << "----------------------------------------" << el;

            // Get the address data from the employee
            address display_address_data = employees[i].get_home_address();

            // Print the address details
            cout << left << setw(20) << "Street:" << display_address_data.street_name << el;
            cout << "----------------------------------------" << el;
            cout << left << setw(20) << "Nearby landmarks:" << display_address_data.near_by_landmarks << el;
            cout << "----------------------------------------" << el;
            cout << left << setw(20) << "Building Number:" << display_address_data.building_number << el;
            cout << "----------------------------------------" << el;
            cout << left << setw(20) << "Floor Number:" << display_address_data.floor_number << el;
            cout << "----------------------------------------" << el;
            cout << left << setw(20) << "Apartment Number:" << display_address_data.apartment_number << el;
            cout << "----------------------------------------" << el;

            // Print the remaining employee details
            cout << left << setw(20) << "Role:" << employees[i].get_role() << el;
            cout << "----------------------------------------" << el;
            cout << left << setw(20) << "Salary:" << fixed << setprecision(2) << employees[i].get_salary() << el;

            // Separate each employee with two lines
            cout << "========================================" << el;
            cout << el;
        }
    }
    void display_employee_for_save(Employee display_data) {
        system(CLEAR);
        cout << "----------------------------------------" << el;
        cout << left << setw(20) << "ID:" << display_data.get_id() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Name:" << display_data.get_name() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Age:" << display_data.get_age() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Street:" << display_data.get_home_address().street_name << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Nearby landmarks:" << display_data.get_home_address().near_by_landmarks << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Building Number:" << display_data.get_home_address().building_number << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Floor Number:" << display_data.get_home_address().floor_number << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Apartment Number:" << display_data.get_home_address().apartment_number << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Role:" << display_data.get_role() << el << "----------------------------------------" << el;
        cout << left << setw(20) << "Salary:" << fixed << setprecision(2) << display_data.get_salary() << el << "----------------------------------------" << el;
    }
};
#endif