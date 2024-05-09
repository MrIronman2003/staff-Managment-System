#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream> 

using namespace std;

struct address {
    string street_name, near_by_landmarks;
    int building_number = 0; // Initialize building_number
    int floor_number = 0; // Initialize floor_number
    int apartment_number = 0; // Initialize apartment_number

    void save(ofstream& outFile) {
        outFile << street_name << "\n" << near_by_landmarks << "\n";
        outFile << building_number << "\n" << floor_number << "\n" << apartment_number << "\n";
    }

    void load(ifstream& inFile) {
        getline(inFile, street_name);
        getline(inFile, near_by_landmarks);
        inFile >> building_number;
        inFile.ignore();
        inFile >> floor_number;
        inFile.ignore();
        inFile >> apartment_number;
        inFile.ignore();
    }
};

class Employee {
private:
    // Declare private member variables
    long long ID = 0;
    int age = 0; // Initialize age
    float salary = 0.0f; // Initialize salary
    string name, role;
    address home_address;

public:
    void save(ofstream& outFile) {
        outFile << ID << "\n" << name << "\n" << age << "\n";
        home_address.save(outFile);
        outFile << role << "\n" << salary << "\n";
    }

    void load(ifstream& inFile) {
        inFile >> ID;
        inFile.ignore();  // Ignore newline character
        getline(inFile, name);
        inFile >> age;
        inFile.ignore();  // Ignore newline character
        home_address.load(inFile);
        getline(inFile, role);
        inFile >> salary;
        inFile.ignore();  // Ignore newline character
    }
    // Default constructor
    Employee() {}

    // Parameterized constructor
    Employee(long long id, string n, int a, address home, string r, float s)
        : ID(id), name(n), age(a), home_address(home), role(r), salary(s) {}

    // Copy constructor
    Employee(const Employee& other)
        : ID(other.ID), name(other.name), age(other.age), home_address(other.home_address),
        role(other.role), salary(other.salary) {}


    // Define public getter methods
    long long get_id() const {
        return ID;
    }
    string get_name() const {
        return name;
    }
    int get_age() const {
        return age;
    }
    address get_home_address() const {
        return home_address;
    }
    string get_role() const {
        return role;
    }
    float get_salary() const {
        return salary;
    }

    // Define public setter methods
    void set_id(long long id) {
        ID = id;
    }
    void set_name(string n) {
        name = n;
    }
    void set_age(int a) {
        age = a;
    }
    void set_home_address(address home) {
        home_address = home;
    }
    void set_role(string r) {
        role = r;
    }
    void set_salary(float s) {
        salary = s;
    }

};
#endif
