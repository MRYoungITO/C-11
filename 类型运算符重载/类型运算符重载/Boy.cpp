#include <sstream>
#include "Boy.h"

int Boy::LAST_ID = 0;

Boy::Boy(const char* name, int age, int salary, int darkHorse)
{
	if (!name) {
		name = "δ����";
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->age = age;
	this->salary = salary;
	this->darkHouse = darkHorse;
	this->id = ++LAST_ID;
}

Boy::~Boy()
{
	if (name) {
		delete name;
	}
}

Boy::Boy(int salary)
{
	const char* defaultName = "δ����";

	this->name = new char[strlen(defaultName) + 1];
	strcpy_s(this->name, strlen(defaultName) + 1, defaultName);
	this->age = 0;
	this->salary = salary;
	this->darkHouse = 0;
	this->id = ++LAST_ID;
}

Boy::Boy(const char* name) 
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->age = 0;
	this->salary = 0;
	this->darkHouse = 0;
	this->id = ++LAST_ID;
}

string Boy::description()
{
	stringstream ret;
	ret << "ID:" << id << "\t����:" << name << "\t����:" << age
		<< "\tн��:" << salary << "\t����ϵ��:" << darkHouse;
	return ret.str();
}

Boy& Boy::operator=(const Boy& boy)
{
	if (name) {
		delete name;  //�ͷ�ԭ�����ڴ�
	}
	name = new char[strlen(boy.name) + 1];
	strcpy_s(name, strlen(boy.name) + 1, boy.name);

	this->age = boy.age;
	this->salary = boy.salary;
	this->darkHouse = boy.darkHouse;
	//  this->id = boy.id;  // ����������ȷ���Ƿ�Ҫ����id
	return *this;
}

bool Boy::operator>(const Boy& boy)
{
	// ����һ���ȽϹ���
	// н�� * ����ϵ�� + (100-����) * 1000
	if (this->power() > boy.power()) {
		return true;
	}
	else {
		return false;
	}
}

bool Boy::operator<(const Boy& boy)
{
	if (this->power() < boy.power()) {
		return true;
	}
	else {
		return false;
	}
}

bool Boy::operator==(const Boy& boy)
{
	if (this->power() == boy.power()) {
		return true;
	}
	else {
		return false;
	}
}

Boy::operator int() const
{
	return power();
}

Boy::operator char* () const 
{
	return this->name;
}

int Boy::operator[](string index) const
{
	if (index == AGE_KEY) {
		return age;
	}
	else if (index == SALARY_KEY) {
		return salary;
	}
	else if (index == DARK_HORSE_KEY) {
		return darkHouse;
	}
	else if (index == POWER_KEY) {
		return power();
	}
	else {
		return -1;
	}
}

int Boy::operator[](int index) const
{
	if (index == AGE) {
		return age;
	}
	else if (index == SALARY) {
		return salary;
	}
	else if (index == DARK_HORSE) {
		return darkHouse;
	}
	else if (index == POWER) {
		return power();
	}
	else {
		return -1;
	}
}

// �÷�ʽ���ʺ�
//ostream& Boy::operator<<(ostream& os) const
//{
//	os << "ID:" << id << "\t����:" << name << "\t����:" << age
//		 << "\tн��:" << salary << "\t����ϵ��:" << darkHouse;
//	return os;
//}

int Boy::power() const
{
	// н�� * ����ϵ�� + (100-����) * 1000
	int ret = salary * darkHouse + (100 - age) * 1000;
	return ret;
}

ostream& operator<<(ostream& os, const Boy& boy) 
{
	os << "ID:" << boy.id << "\t����:" << boy.name << "\t����:" << boy.age
		<< "\tн��:" << boy.salary << "\t����ϵ��:" << boy.darkHouse;
	return os;
}

istream& operator>>(istream& is, Boy& boy) 
{
	string name2;
	is >> name2 >> boy.age >> boy.salary >> boy.darkHouse;
	boy.name = (char*)malloc((name2.length() + 1) * sizeof(char));
	strcpy_s(boy.name, name2.length() + 1, name2.c_str());
	return is;
}