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

vector<Employee> Database::Employees_data;

class Out_Put_Handler {
	Database data;
	Employee display_employee_data;
	address address_data;
public:
	void display_menu() {

	}
	void display_employee_details(int index) {
		system("cls");
		//display ID
		cout << "ID: " << display_employee_data.get_id() << el;
		//Display Name
		cout << "Name: " << display_employee_data.get_name() << el;
		//Display Age
		cout << "Age: " << display_employee_data.get_age() << el;
		//Identefying address data
		address_data = display_employee_data.get_home_address();
		//display address data
		cout << "Address: " << el << "Street: " << address_data.street_name << el;
		cout << "Building Number: " << address_data.building_number << el;
		cout << "Floor Number: " << address_data.floor_number << el;
		cout << "Apartment Number: " << address_data.apartment_number << el;
		cout << "Nearby landmarks: " << address_data.near_by_landmarks << el;
		//Display role
		cout << "Role: " << display_employee_data.get_id() << el;
		//Display Salary
		cout << "Salary: " << display_employee_data.get_id() << el;
	}
};
#endif