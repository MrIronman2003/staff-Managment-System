#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the Employee class

struct address {
    string street_name, near_by_landmarks;
    int building_number, floor_number, apartment_number;
};

class Employee
{
private:
    // Declare private member variables
    int ID, age;
    float salary;
    string name, role;
    address home_address;

public:
    // Define public getter methods
    int get_id() { 
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
    void set_id(int id) { 
        ID = id; 
    }
    void set_name(string n) { 
        name = n; 
    }
    void set_age(int a) { 
        age = a; 
    }
    void set_home_Address(address home) { 
        home_address = home; }
    void set_role(string r) { role = r; 
    }
    void set_salary(float s) { 
        salary = s; 
    }
};


#endif