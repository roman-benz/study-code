#include <stdlib.h>
#include <string>
#include <iostream>

class User {
protected: 
	std::string name;
	int id;

public:
	User(std::string name, int id) {
		this->name = name;
		this->id = id;
	};

	void printInfo() {
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "ID. " << this->id << std::endl;
	}
};

class Student : protected User {
protected:
	double annual_grade_average;

public:
	Student(std::string name, int id, double annual_grade_average) : User(name, id) {
		this->annual_grade_average = annual_grade_average;
	}

	void printRole() {

		std::cout << "Name: " << this->name << std::endl;
		std::cout << "ID: " << this->id << std::endl;
		std::cout << "Grade: " << this->annual_grade_average<< std::endl;

	}
};

class Instructor : protected User {
protected:
	double annual_salary;

public:
	Instructor(std::string name, int id, double annual_salary) : User(name, id) {
		this->annual_salary = annual_salary;
	}

	void printRole() {

			std::cout << "Name: " << this->name << std::endl;
			std::cout << "ID: " << this->id << std::endl;
			std::cout << "Annual Salary: " << this->annual_salary << std::endl;

	}
	
};