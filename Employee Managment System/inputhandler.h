#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <string>
#include <limits>
#include "database.h"
#include "employee.h"
#include "validator.h"

using namespace std;

//Define the input handler class
class Input_Handler {
private:
	string input;
public:
	string get_input() {
		input = "0"; //reset input value
		getline(cin, input);
		return input;
	}
};


#endif
