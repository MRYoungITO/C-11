#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

using namespace std;

#define ADDR_LEN 32

//����һ��"����"
class Human {
public:
	Human();	//Ĭ�Ϲ��캯��(��������)
	Human(string name, int age, int salary);	//�Զ���Ĺ��캯��(������)
	Human(const Human& copy);	//�Զ���Ŀ������캯��

	// =��������غ���
	Human& operator=(const Human& assignment);

	// ��������
	~Human();

	void eat();
	void sleep();
	void play();
	void work();
	void description(); 	//test

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

string Human::getName() {	// �����������const, ���ڲ��ĳ�Ա�޷��޸�
	return name;
}

int Human::getAge() {
	return age;
}

int Human::getSalary() {
	return salary;
}

Human::Human() {
	cout << "���ù��캯��: " << this << endl;
	name = "����";
	age = 18;
	salary = 20000;

	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, "China");
}

Human::Human(string name, int age, int salary) {
	cout << "�����Զ���Ĺ��캯��" << endl;
	this->name = name;	//this��һ�������ָ��, ָ�����������
	this->age = age;
	this->salary = salary;

	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, "China");
}

Human::Human(const Human& copy) {
	cout << "���ÿ������캯��" << endl;
	name = copy.name;
	age = copy.age;
	salary = copy.salary;


	addr = new char[ADDR_LEN];
	strcpy_s(addr, ADDR_LEN, copy.addr);		//��ȿ���
}

void Human::setAddr(const char* newAddr) {
	if (!newAddr) {
		return;
	}

	strcpy_s(addr, ADDR_LEN, newAddr);
}

void Human::description() {
	cout << "name:" << name
		<< " age:" << age
		<< " salary:" << salary
		<< " addr:" << addr << endl;
}

// ���ú��� showMsg(h1);
// �ڽ��в�������ʱ, �Զ�ִ��: Human man = h1;
void showMsg(Human man) {
	cout << man.getName() << "�Ļ�����Ϣ: ";
	man.description();
}

Human getBetterMan(Human man1, Human man2) {
	if (man1.getSalary() > man2.getSalary()) {
		return man1;
	}
	else {
		return man2;
	}
}

Human& Human::operator=(const Human& assignment) {
	// ��ֹ������Լ���ֵ  f1 = f1;
	if (this == &assignment) {
		return *this;
	}

	// ����ִ��: f1 = f2;
	// �ͻ����: f1.opreator= (f2);
	name = assignment.name;
	age = assignment.age;
	salary = assignment.salary;

	// ����б�Ҫ, ��Ҫ���ͷ��Լ�����Դ(��̬�ڴ�)
	//delete addr;
	addr = new char[ADDR_LEN];
	// ���
	strcpy_s(addr, ADDR_LEN, assignment.addr);

	// ���ض����������, ��Ϊ�˷�������ʽ���� ����: f1 = f2 = f3;
	return *this;
}

Human::~Human() {
	cout << "������������" << this << endl;
	delete addr;
}

void test() {
	Human h1;
	{
		Human h2;
	}
	cout << "test() end. " << endl;
}

int main(void) {
	test();

	/*
	Human f1("Young", 28, 30000), f2;
	f2 = f1;		// �Զ����ø�ֵ���캯��! λ����(ǳ����)
	f1.description();
	f2.description();

	cout << "-----------------------------------" << endl;

	f1.setAddr("�¼���");
	f1.description();
	f2.description();
	*/
	/*
	Human f1(18, 20000, "Young");
	Human f2 = f1;
	Human f3 = f1;
	Human f4(f1);

	Human F4[4] = { f1,f2,f3,f4 };
	*/
	/*
	Human h1(28, 35000, "young");	//ʹ���Զ���Ĺ��캯��
	Human h2(29, 40000, "young");

	getBetterMan(h1, h2);		// ������һ����ʱ����
	*/
	system("pause");
	return 0;
}