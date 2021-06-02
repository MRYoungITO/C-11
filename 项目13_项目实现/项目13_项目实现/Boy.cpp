#include "Boy.h"
#include "Girl.h"
#include <iostream>
#include <sstream>

#define SALARY_FACTOR 0.006

Boy::Boy() {

}

Boy::Boy(const Boy& other) :Single(other.getName(), other.getAge()) {
	salary = other.salary;
	//name = other.name;
	//age = other.age;
}

Boy::Boy(int age, string name, int salary) : Single(name, age) {
	//this->age = age;
	//this->name = name;
	this->salary = salary;
}

Boy::~Boy() {

}

/*
int Boy::getAge() const {
return age;
}
string Boy::getName() const {
return name;
}
*/

int Boy::getSalary() const {
	return salary;
}

bool Boy::satisfied(const Girl& s) const {
	if (s.getYanZhi() >= salary * SALARY_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}

string Boy::description()const {
	// �淶һ���ַ�����ʽ:
	// �Ա�:��\t\t\t����:Rock\t\t\tн��:35000\t\t\t����:39

	stringstream ret;
	//ret << name << "-��-н��(" << salary << ")-����(" << age << ")";
	//ret << getName() << "-��-н��(" << salary << ")-����(" << getAge() << ")";
	ret << "�Ա�:��"
		<< "\t\t\t����:" << name
		<< "\t\t\tн��:" << salary
		<< "\t\t\t����:" << age;
	return ret.str();
}

void Boy::inputBoys(vector<Boy>& boys) {
	int age;
	string name;
	int salary;
	int n = 1;
	while (1) {
		cout << "�������" << n << "λС�������䡾����0��������";
		cin >> age;
		if (age == 0) {
			break;
		}
		cout << "�������" << n << "λС����������";
		cin >> name;
		cout << "�������" << n << "λС����н�ʣ�";
		cin >> salary;
		n++;
		boys.push_back(Boy(age, name, salary));
	}
}

void Boy::inputBoy(Boy& boy)
{
	int age;
	string name;
	int salary;

	cout << "������С�������䣺";
	cin >> age;

	cout << "������С����������";
	cin >> name;

	cout << "������С����н�ʣ�";
	cin >> salary;

	boy = Boy(age, name, salary);
}

bool Boy::operator>(const Boy& boy)
{
	return salary > boy.salary;
}

ostream& operator<<(ostream& os, const Boy& boy)
{
	os << "�Ա�:��"
		<< "\t\t\t����:" << boy.name
		<< "\t\t\tн��:" << boy.salary
		<< "\t\t\t����:" << boy.age;
	return os;
}
