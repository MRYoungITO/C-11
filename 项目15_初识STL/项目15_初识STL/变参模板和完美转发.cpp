#include <iostream>
#include <string>
using namespace std;

#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class student {
public:
	student() {
		cout << "�޲ι��캯��������!" << endl;
	}
	student(int age, string name) {
		this->age = age;
		this->name = name;
		//strncpy_s(this->name, name, 64);
		cout << "�вι��캯��������!" << endl;
		cout << "����: " << this->name << " ����: " << this->age << endl;
	}

	student(const student& s) {
		this->age = s.age;
		this->name = s.name;
		//strncpy_s(this->name, s.name, 64);
		cout << "�������캯��������!" << endl;
	}
	~student() {
		cout << "��������������" << endl;
	}
private:
	int age;
	string name;
};

int main(void) {
	//vector<int> vectInt(10, 0);
	deque<int> dqInt;
	list<int> lstInt;

	vector<student> vectStu(10);

	cout << "vectStu size:" << vectStu.size() << endl;
	cout << "vectStu capacity:" << vectStu.capacity() << endl;

	//����ѧ��

	//����һ �ȶ������, �ڲ���
	//student xiaoHua(18, "��У��");
	//vectStu.push_back(xiaoHua);

	//������ ֱ�Ӳ�����ʱ����
	//vectStu.push_back(student(19, "����"));

	//C++11 ������ ���ģ�������ת��

	vectStu.emplace_back(19, "����"); //push_back()
	cout << "vectStu size(1):" << vectStu.size() << endl;
	cout << "vectStu capacity(1):" << vectStu.capacity() << endl;

	vectStu.emplace(vectStu.end(), 18, "��У��");  //�൱�� insert()
	cout << "vectStu size(2):" << vectStu.size() << endl;
	cout << "vectStu capacity(2):" << vectStu.capacity() << endl;

	system("pause");
	return 0;

}