#ifndef STAFFMANAGMENTSYSTEM_H
#define STAFFMANAGMENTSYSTEM_H

#include "main.h"
#include "database.h"
#include "employee.h"
#include "validator.h"
#include "inputhandler.h"
#include "menu.h"

class Staff_Management_System : public Database, public Menu {
	Database initialize;
	Out_Put_Handler menu_call;
public:
	void run() {
		initialize.restore_data_from_file();
		while (1) {
			display_menu();
			select_option();
		}
	}

};
#endif
