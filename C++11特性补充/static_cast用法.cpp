#include <iostream>
#include <Windows.h>

using namespace std;

class Animal {
public:
	virtual void cry() = 0;
};

class Cat : public Animal {
public:
	virtual void cry() {
		cout << "������" << endl;
	}
};

class Dog : public Animal {
public:
	virtual void cry() {
		cout << "������" << endl;
	}
};

int main(void) {

	//��һ����� ������֮�������ת��
	Dog* dog1 = new Dog();
	Animal* a1 = static_cast<Animal*>(dog1); //�����ָ��ת�͵�����ָ��
	a1->cry();
	
	Dog* dog1_1 = static_cast<Dog*>(a1);	 //�����ָ��ת�͵������ָ��
	Cat* cat1 = static_cast<Cat*>(a1);		 //���ൽ����, �з���, �����ǲ��е�, �������

	Dog dog2;
	Animal& a2 = static_cast<Animal&>(dog2); //���������ת�͵����������
	Dog& dog2_2 = static_cast<Dog&>(a2);	 //���ൽ���������
	a2.cry();
	delete dog1;

	//�ڶ��� �������͵�ת��
	int kk = 234;
	char cc = static_cast<char>(kk);

	//������ �ѿ�ָ��ת����Ŀ�����͵Ŀ�ָ��
	int* p = static_cast<int*>(NULL);
	Dog* dp = static_cast<Dog*>(NULL);

	//������ ���κ����͵ı��ʽת����void����
	int* q = new int[10];
	void* vq = static_cast<void*>(q);
	vq = q;

	system("pause");
	return 0;
}