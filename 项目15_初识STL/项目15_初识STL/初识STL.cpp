#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class student {
public:
	student(int age, const char* name) {
		this->age = age;
		strncpy_s(this->name, name, 64);
	}

	student(const student& s) {
		this->age = s.age;
		strncpy_s(this->name, s.name, 64);
		cout << "�������캯��������!" << endl;
	}
public:
	int age;
	char name[64];
};

//�����д��ָ��
void demo3() {
	vector<student*> v1;

	student s1(18, "��С��");
	student s2(19, "����˧");

	v1.push_back(&s1);
	v1.push_back(&s2);

	cout << "v1 ��ѧ������: " << v1.size() << endl;

	//��ʽ1, �±����
	/*for (unsigned int i = 0; i < v1.size(); i++) {
		cout << v1[i].name << ": " << v1[i].age << endl;
	}*/

	//��ʽ2, ����������
	//�ڶ����� ������
	//1 2 3 4
	//it
	vector<student*>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << (**it).name << ": " << (**it).age << endl;
	}
}

void demo2() {
	vector<student> v1;

	student s1(18, "��С��");
	student s2(19, "����˧");

	v1.push_back(s1);
	v1.push_back(s2);

	cout << "v1 ��ѧ������: " << v1.size() << endl;

	//��ʽ1, �±����
	/*for (unsigned int i = 0; i < v1.size(); i++) {
		cout << v1[i].name << ": " << v1[i].age << endl;
	}*/

	//��ʽ2, ����������
	//�ڶ����� ������
	//1 2 3 4
	//it
	vector<student>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << (*it).name << ": " << (*it).age << endl;
	}
}

void demo1() {
	//��һ���� ����
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(3);

	cout << "v1 ��Ԫ�ظ���" << v1.size() << endl;
	cout << "v1�б����Ԫ��:" << endl;
	//��ʽ1, �±����
	/*for (unsigned int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}*/

	//��ʽ2, ����������
	//�ڶ����� ������
	//1 2 3 4
	//it
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		cout << *it << endl;
	}

	//�������� �㷨
	int ncount = count(v1.begin(), v1.end(), 90);
	cout << "v1 ����ֵΪ90 ��Ԫ�ظ���:" << ncount << endl;

}

int main(void) {
	demo3();

	system("pause");
	return 0;
}