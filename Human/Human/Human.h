#pragma once

#include <string>

using namespace std;

#define ADDR_LENS 64

class Human {
public:
	Human();
	Human(string name, int age, int salary, string bldType);
	Human(const Human& copy);
	Human& operator=(const Human& assignment);
	~Human();
	void description() const;
	void setAddr(const char* newAddr);
	Human& compare(Human& comparison);
	Human* compare2(Human* comparison);

	// ��ľ�̬��Ա����
	static int getHumanCount();

private:
	string name;
	int age;
	int salary;
	char* addr;

	const string bloodType;	//const string bloodType; = "A";	C++11/��֧��, "���ڳ�ʼֵ"

	static int humanCount;
};