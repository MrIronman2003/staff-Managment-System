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

int main() {
	Database Employees_database;
	Menu main_menu;
	while (1) {
		main_menu.display_menu();
	}

	return 0;
}