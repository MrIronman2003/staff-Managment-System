#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <fstream>
#include <vector>
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
#endif
