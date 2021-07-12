#include <iostream>
#include <Windows.h>

using namespace std;

class Animal {
public:
	void cry() {
		cout << "�����" << endl;
	}
};

class Cat : public Animal {
public:
	void cry() {
		cout << "������" << endl;
	}
};

class Dog : public Animal {
public:
	void cry() {
		cout << "������" << endl;
	}
};

int main(void) {

	//�÷�һ ��ֵ��ָ��֮���ת��
	int* p = reinterpret_cast<int*>(0x888888);
	int val = reinterpret_cast<int>(p);
	

	//�÷��� ��ͬ����ָ�������֮���ת��
	Dog dog1;
	Animal* a1 = &dog1;
	a1->cry();

	Cat* cat_p = reinterpret_cast<Cat*>(a1);

	Dog* dog1_p = reinterpret_cast<Dog*>(a1);
	Dog* dog2_p = static_cast<Dog*>(a1); //�������static_cast, static_cast����

	//Cat* cat1_p = static_cast<Cat*>(a1);
	//Cat* cat1_p = static_cast<Cat*>(dog1_p); //NO! ��ͬ����ָ��ת������ʹ��static_cast
	Cat* cat1_p =  reinterpret_cast<Cat*>(dog1_p);

	Animal& a2 = dog1;
	Dog& dog3 = reinterpret_cast<Dog&>(a2); //����ǿת�÷�

	dog1_p->cry();
	dog2_p->cry();

	cat1_p->cry();

	system("pause");
	return 0;
}