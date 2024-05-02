#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Define the Employee class

struct address {
    string street_name, near_by_landmarks;
    int building_number = 0; // Initialize building_number
    int floor_number = 0; // Initialize floor_number
    int apartment_number = 0; // Initialize apartment_number
};


class Employee
{
private:
    // Declare private member variables
    long long ID = 0;
    int age = 0; // Initialize age
    float salary = 0.0f; // Initialize salary
    string name, role;
    address home_address;

public:
    // Define public getter methods
    long long get_id() {
        return ID;
    }
    string get_name() {
        return name;
    }
    int get_age() {
        return age;
    }
    address get_home_address() {
        return home_address;
    }
    string get_role() {
        return role;
    }
    float get_salary() {
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

    const address& get_home_address() const {
        return home_address;
    }

    // Inside the Employee class definition
    bool operator==(const Employee& other) const {
        return ID == other.ID; // Compare IDs
    }

};
#endif
