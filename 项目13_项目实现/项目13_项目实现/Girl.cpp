#include <sstream>
#include <iostream>
#include <iomanip>
#include "Girl.h"
#include "Boy.h"

#define YANZHI_FACTOR 100

Girl::Girl() {

}

Girl::Girl(int age, string name, int yanZhi) :Single(name, age) {
	//this->age = age;
	//this->name = name;
	this->yanZhi = yanZhi;
}

Girl::~Girl() {

}

/*
int Girl::getAge() const {
return age;
}
string Girl::getName() const {
return name;
}
*/

int Girl::getYanZhi() const {
	return yanZhi;
}

bool Girl::satisfied(const Boy& s) const {
	if (s.getSalary() >= yanZhi * YANZHI_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}

string Girl::description() const {
	// �淶һ���ַ�����ʽ:
	//�Ա�:Ů\t\t\t����:����\t\t\t��ֵ:90\t\t\t����:25

	stringstream ret;
	//ret << name << "-Ů-��ֵ(" << yanZhi << ")-����(" << age << ")";
	//ret << getName() << "-Ů-��ֵ(" << yanZhi << ")-����(" << getAge() << ")"; 
	ret << "�Ա�:Ů"
		<< "\t\t\t����:" << name
		<< "\t\t\t��ֵ:" << setw(3) << setiosflags(ios::left) << yanZhi
		<< "\t\t\t����:" << age;
	return ret.str();
}

void Girl::inputGirls(vector<Girl>& girls) {
	int age;
	string name;
	int yanZhi;
	int n = 1;
	while (1) {
		cout << "�������" << n << "λС�������䡾����0��������";
		cin >> age;
		if (age == 0) {
			break;
		}
		cout << "�������" << n << "λС����������";
		cin >> name;
		cout << "�������" << n << "λС������ֵ��";
		cin >> yanZhi;
		n++;
		girls.push_back(Girl(age, name, yanZhi));
	}
}

void Girl::inputGirl(Girl& girl)
{
	int age;
	string name;
	int yanZhi;

	cout << "������С�������䣺";
	cin >> age;

	cout << "������С����������";
	cin >> name;

	cout << "������С������ֵ��";
	cin >> yanZhi;

	girl = Girl(age, name, yanZhi);
}

bool Girl::operator>(const Girl& girl)
{
	return yanZhi > girl.yanZhi;
}

ostream& operator<<(ostream& os, const Girl& girl)
{
	os << "�Ա�:Ů"
		<< "\t\t\t����:" << girl.name
		<< "\t\t\t��ֵ:" << setw(3) << setiosflags(ios::left) << girl.yanZhi
		<< "\t\t\t����:" << girl.age;
	return os;
}
