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

class Staff_Managment_System : public Database, public Menu {
	Database initialize;
	Out_Put_Handler menu_call;
public:
	void run() {
		initialize.restore_data_from_file();
		while (1) {
			display_menu();
		}
	}

};
#endif