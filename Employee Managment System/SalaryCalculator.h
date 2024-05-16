#ifndef SALARYCALCULATOR_H
#define SALARYCALCULATOR_H

#include "main.h"

class SalaryCalculator {
private:
	float salary, net_salary;
	int working_months;

public:
	SalaryCalculator() {
		salary = 0.0f;
		net_salary = 0.0f;
		working_months = 12;
	}

	void set_salary(float s) {
		salary = s;
	}

	float calculate_salary() {
		net_salary = salary * working_months;
		return net_salary;
	}
};
#endif