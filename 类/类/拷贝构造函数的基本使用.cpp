#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

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

private:
	string name;
	int age;
	int salary;
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
	string name;
	int age;
	int salary;
}

// Human h2 = h1;
Human::Human(const Human& copy) {	//const Human &copy = h1;
	cout << "���ÿ������캯��" << endl;
	
	name = copy.name;
	age = copy.age;
	salary = copy.salary;
}

Human::Human(int age, int salary, string name) {
	cout << "�����Զ���Ĺ��캯��" << endl;
	this->age = age;	//this��һ�������ָ��, ָ�����������
	this->salary = salary;
	this->name = "����";
}

void Human::description() {
	cout << "age:" << age 
		<< " name:" << name 
		<< " salary:" << salary << endl;
}

int main(void) {
	Human h1(28,35000,"young");	//ʹ���Զ���Ĺ��캯��
	Human h2 = h1;	//���ÿ������캯��
	Human h3(h1);		//���ÿ������캯��

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