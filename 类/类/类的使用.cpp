#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

// ����һ��"����"
class Human {
public:	//���е�,	�����
	void eat();		//����, "��Ա����"
	void	sleep();
	void play();
	void work();
	string getname();
	int getAge();
	int gerSalary();

private:
	string name;		//�˴��������������ݳ�Ա
	int age;
	int salary;
};

void Human::eat() {
	cout << "��ը��, ��ơ��!" << endl;
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

string Human::getname() {
	return name;
}

int Human::getAge() {
	return age;
}

int Human::gerSalary() {
	return salary;
}

int main(void) {
	Human zhangsan;

	system("pause");
	return 0;
}