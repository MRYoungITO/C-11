#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

using namespace std;

#define ADDR_LEN 32

//����һ��"����"
class Human {
public:
	Human();
	Human(int age, int salary, string name);
	Human(const Human&copy);

	void eat();
	void sleep();
	void play();
	void work();
	void description();	//test

	string getName();
	int getAge();
	int getSalary();
	void setAddr(const char* addr);

private:
	string name;
	int age;
	int salary;
	char* addr;		//��ַ
};

void Human::eat() {
	cout << "��ը��, ��ơ��! " << endl;
}

void Human::sleep() {
	cout << "������˯��!" << endl;
}

void Human::play() {
	cout << "���ڳ���!" << endl;
}

void Human::work() {
	cout << "���ڹ���!" << endl;
}

string Human::getName() {
	return name;
}

int Human::getAge() {
	return age;
}

int Human::getSalary() {
	return salary;
}

Human::Human() {
	name = "����";
	age = 18;
	salary = 20000;
}

Human::Human(int age, int salary, string name) {
	cout << "�����Զ���Ĺ��캯��" << endl;
	this->age = age;	//this��һ�������ָ��, ָ�����������
	this->salary = salary;
	this->name = name;;

	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, "China");
}

// Human h2 = h1;
Human::Human(const Human& copy) {	//const Human &copy = h1;
	cout << "���ÿ������캯��" << endl;
	name = copy.name;
	age = copy.age;
	salary = copy.salary;

	//��ȿ���
	addr = new char[ADDR_LEN];
	strcpy_s(this->addr, ADDR_LEN, copy.addr);
}

void Human::setAddr(const char* newAddr) {
	if (!newAddr) {
		return;
	}
	strcpy_s(addr, ADDR_LEN, newAddr);
}

void Human::description() {
	cout << "age:" << age
		<< " name:" << name
		<< " salary:" << salary
		<< " addr:" << addr << endl;
}

int main(void) {
	Human h1(28, 35000, "young");	//ʹ���Զ���Ĺ��캯��
	Human h2 = h1;	//���ÿ������캯��
	Human h3(h1);		//���ÿ������캯��

	h1.description();
	h2.description();
	h3.description();

	h1.setAddr("����");

	cout << "h1�޸ĵ�ַ֮��" << endl;
	h1.description();
	h2.description();
	h3.description();


	/*
	h1.eat();
	h1.play();
	h1.sleep();
	*/
	//cout << h1.getAge() << endl;

	/*
	Human* h2 = &h1;

	cout << "����: " << h2->getName() << endl;
	cout << "����: " << h2->getAge() << endl;
	cout << "н��: " << h2->getSalary() << endl;
	*/
	system("pause");
	return 0;
}