#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class student {
public:
	/*explicit*/ student(int age) {
		this->age = age;
		cout << "age= " << this->age << endl;
	}

	/*explicit*/ student(int age, string name) {
		this->age = age;
		this->name = name;
		cout << "age= " << this->age << "; name= " << this->name << endl;
	}

	~student() {

	}

	int getAge() {
		return this->age;
	}

	string getName() {
		return this->name;
	}

private:
	int age;
	string name;
};

int main(void) {

	student xiaoMing(18);  //��ʾ����
	student xiaoWang = 18; //��ʽ����

	student xiaoua(19, "С��");  //��ʾ����
	student xiaoMei = { 18, "С��" }; //��ʽ���� ��ʼ�������б�, C++11֮ǰ�汾���벻��ͨ��



	system("pause");
	return 0;
}