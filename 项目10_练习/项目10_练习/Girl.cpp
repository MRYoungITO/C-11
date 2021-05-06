#include "Girl.h"
#include "Boy.h"
#include <iostream>
#include <sstream>

#define YANZHI_FACTOR 100

Girl::Girl() {
	age = 0;
	name = "";
	yanZhi = 0;
}

Girl::Girl(int age, string name, int yanZhi) {
	this->age = age;
	this->name = name;
	this->yanZhi = yanZhi;
}

Girl::~Girl() {

}

int Girl::getAge() const {
	return age;
}

string Girl::getName() const {
	return name;
}

int Girl::getYanzhi() const {
	return yanZhi;
}

string Girl::description() const {
	stringstream ret;
	ret << name << "-Ů-(" << yanZhi << ")-����(" << age << ")";
	return ret.str();
}

bool Girl::satisfied(const Boy& boys) const {
	if (boys.getSalary() >= yanZhi * YANZHI_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}

void Girl::inputGirls(vector<Girl>& girls) {
	int age;
	string name;
	int yanZhi;

	int n = 1;
	while (1) {
		cout << "�������" << n << "λС�������䡾����0������:";
		cin >> age;
		if (age == 0) {
			break;
		}
		cout << "�������" << n << "λС��������: ";
		cin >> name;
		cout << "�������" << n << "λС������ֵ: ";
		cin >> yanZhi;

		girls.push_back(Girl(age, name, yanZhi));
		n++;
	}
}
