#ifndef STAFFMANAGMENTSYSTEM_H
#define STAFFMANAGMENTSYSTEM_H

#include <iostream>
#include <string>
#include <limits>
#include "database.h"
#include "employee.h"
#include "validator.h"
#include "inputhandler.h"
#include "menu.h"

using namespace std;
#define el "\n"

class Staff_Managment_System : public Database, public Menu{
public:
	void run() {
		while (1) {
			display_menu();
		}
	}

};
#endif