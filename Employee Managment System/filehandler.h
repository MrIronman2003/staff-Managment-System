#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <fstream>
#include <vector>
#include <iomanip>
#include "SalaryCalculator.h"
#include "database.h"


// Function to save data in a vector into a file
void saveData(vector<Employee>& employees, const string& filename) {
    ofstream outFile(filename);
    for (Employee& employee : employees) {
        employee.save(outFile);
    }
    outFile.close();
}


// Function to restore data from a file and resave it in the vector
void restoreData(vector<Employee>& employees, const string& filename) {
    ifstream inFile(filename);
    Employee employee;
    while (inFile.peek() != EOF) {
        employee.load(inFile);
        employees.push_back(employee);
    }
    inFile.close();
}

void saveExcel(const vector<Employee>& employees, const string& filename) {
	SalaryCalculator salary_calculator;
    ofstream outFile(filename);
    outFile << "Employee Number,ID,Name,Age,Street Name,Nearby Landmark,Building Number,Floor Number,Apartment Number,Role,Salary,Yearly Salary\n";
    // Write the headers
    for (size_t i = 0; i < employees.size(); ++i) {
        const Employee& employee = employees[i];
        salary_calculator.set_salary(employee.get_salary());
        outFile << i + 1 << ","
            << employee.get_id() << ","
            << employee.get_name() << ","
            << employee.get_age() << ","
            << employee.get_home_address().street_name << ","
            << employee.get_home_address().near_by_landmarks << ","
            << employee.get_home_address().building_number << ","
            << employee.get_home_address().floor_number << ","
            << employee.get_home_address().apartment_number << ","
            << employee.get_role() << ","
            << fixed << setprecision(2) << employee.get_salary() << ","
            << fixed << setprecision(2) << salary_calculator.calculate_salary() << "\n";
    }
    outFile.close();
}
#endif
