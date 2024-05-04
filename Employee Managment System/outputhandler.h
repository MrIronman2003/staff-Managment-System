#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include <iostream>
#include <string>
#include <limits>
#include "database.h"
#include "employee.h"
#include "validator.h"
#include "inputhandler.h"

using namespace std;
#define el '\n'

class Out_Put_Handler {
	Database data;
	Employee display_employee_data;
	address display_address_data;
public:
	void display_menu() {

	}
    void display_employee_details(int index) {
        system("cls");

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
        cout << left << setw(20) << "Salary:" << display_employee_data.get_salary() << el << "----------------------------------------" << el;
    }


};
#endif