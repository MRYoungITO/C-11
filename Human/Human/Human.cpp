#include "Human.h"
#include <iostream>

int Human::humanCount = 0;

Human::Human() {
	name = "Young";
	age = 28;
	salary = 30000;
	addr = new char[ADDR_LENS];
	strcpy_s(addr, ADDR_LENS, "�й�");
	humanCount++;
}

Human::Human(string name, int age, int salary) {
	this->name = name;
	this->age = age;
	this->salary = salary;
	addr = new char[ADDR_LENS];
	strcpy_s(this->addr, ADDR_LENS, "�й�");
	humanCount++;
}

Human::Human(const Human& copy) {
	name = copy.name;
	age = copy.age;
	salary = copy.salary;
	addr = new char[ADDR_LENS];
	strcpy_s(addr, ADDR_LENS, copy.addr);
	humanCount++;
}

Human& Human::operator=(const Human& assignment) {
	name = assignment.name;
	age = assignment.age;
	salary = assignment.salary;
	addr = new char[ADDR_LENS];
	strcpy_s(addr, ADDR_LENS, assignment.addr);

	return *this;		// �������������
}

void Human::descripiton() {
	cout << "name:" << name
		<< " age:" << age
		<< " salary:" << salary
		<< " addr:" << addr << endl;
}

void Human::setAddr(const char* newAddr) {

	strcpy_s(this->addr, ADDR_LENS, newAddr);
}

Human::~Human() {
	delete addr;
}

Human& Human::compare(Human& comparison) {
	if (salary > comparison.salary) {
		return *this;
	}
	else {
		return comparison;
	}
}

Human* Human::compare2(Human* comparison) {
	if (salary > comparison->salary) {
		return this;
	}
	else {
		return comparison;
	}
}

int Human::getHumanCount() {
	return humanCount;
}