#ifndef SALARYCALCULATOR_H
#define SALARYCALCULATOR_H
#include <iostream>
#include <string>

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

	void set_working_months(int m) {
		working_months = m;
	}

	float calculate_salary() {
		net_salary = salary * working_months;
		return net_salary;
	}
};
#endif