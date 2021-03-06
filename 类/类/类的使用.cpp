#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Human {
public:
	Human();
	Human(int age, int salary,string name);
	void eat();
	void sleep();
	void play();
	void work();

	string getName();
	int getAge();
	int getSalary();

private:
	string name;
	int age;
	int salary;
};

void Human::eat() {
	cout << "吃炸鸡, 喝啤酒! " << endl;
}

void Human::sleep() {
	cout << "我正在睡觉!" << endl;
}

void Human::play() {
	cout << "我在唱歌!" << endl;
}

void Human::work() {
	cout << "我在工作!" << endl;
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
	name = "Young";
	age = 18;
	salary = 15000;
}

Human::Human(int age, int salary, string name) {
	cout << "调用 Human(int age, int salary, string name)" << endl;
	this->age = age;	//this是一个特殊的指针, 指向这个对象本身
	this->salary = salary;
	this->name = "无名";
}

int main1(void) {
	Human h1;	//使用自定义的构造函数
	Human h2(28, 28000, "lao_young");	//调用自定义的构造函数
	cout << "姓名: " << h2.getName() << endl;
	cout << "年龄: " << h2.getAge() << endl;
	cout << "薪资: " << h2.getSalary() << endl;
	/*
	h1.eat();
	h1.play();
	h1.sleep();
	*/
	//cout << h1.getAge() << endl;
	
	/*
	Human* h2 = &h1;

	cout << "姓名: " << h2->getName() << endl;
	cout << "年龄: " << h2->getAge() << endl;
	cout << "薪资: " << h2->getSalary() << endl;
	*/
	system("pause");
	return 0;
}