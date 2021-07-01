#include <deque>
#include <iostream>
#include <Windows.h>

using namespace std;

class student {
public:
	student(int age) {
		cout << "construct student, age: " << age << endl;
		this->age = age;
	}

	student(const student& other) {
		cout << "�������캯��: " << endl;
		this->age = other.age;
	}

	~student() {
		cout << "desconstruct student. " << endl;
	}

	int getAge() {
		return this->age;
	}

private:
	int age;
};

int main(void){

	//1. deque ��ģ��Ĭ�Ϲ���
	deque<int> deqIntA;		//���int��deque����
	deque<float> deqFloat;  //���float��deque����
	deque<student>	deqStu; //���student��deque����

	deque<student*> deqStuP;

	//deqInt.push_back(1);
	deqFloat.push_back(0.1f);
	deqStu.push_back(student(18));

	//2. deque ���εĹ���

	//��ʽһ: ��������
	deque<int> deqIntB(deqIntA.begin(), deqIntA.end()); //���캯����[begin, end)�����е�Ԫ�ؿ���������

	//��ʽ��: ָ��n ��Ԫ�ؽ��п���
	deque<int> deqIntC(10, 0);

	//��ʽ��: ��������
	deque<int> deqIntD(deqIntC);

	/*cout << "deqIntD �е�Ԫ��: " << endl;
	for (unsigned int i = 0; i < deqIntD.size(); i++) {
		cout << deqIntD[i] << endl;
	}*/

	//dequeͷ����β��������Ƴ�����
	deqIntA.push_back(1);
	deqIntA.push_back(2);
	deqIntA.push_back(3);
	deqIntA.push_back(4);
	deqIntA.push_back(5);
	//deqIntA.push_back(6);

	//��ͨ������
	/*for (deque<int>::iterator it = deqIntA.begin(); it != deqIntA.end(); it++) {
		(*it)++;
		cout << *it;
		cout << " ";
	}
	cout << endl;*/

	//����������
	/*deque<int>::const_iterator cit = deqIntA.cbegin();
	for (; cit != deqIntA.cend(); cit++) {
		cout << *cit;
		cout << " ";
	}
	cout << endl;*/

	//��ת�ĵ�����
	for (deque<int>::reverse_iterator rit = deqIntA.rbegin(); rit != deqIntA.rend(); rit++) {
		cout << *rit;
		cout << " ";
	}
	cout << endl;
	//int i1 = deqIntA.at(0); //i1 = 1;
	//int i2 = deqIntA[1];

	//deqIntA.at(0) = 666;
	//deqIntA[1] = 888;

	//deqIntA[5] = 999;  //Խ�����, ���򱨴�
	//int iFront = deqIntA.front(); //666
	//int iBack = deqIntA.back();	  //5

	//iFront++;
	//iBack++;

	//deqIntA.front() = iFront;
	//deqIntA.back() = iBack;
	//
	// 1 2 3 4 5 6
	//deqIntA.pop_front();
	// 2 3 4 5 6
	//deqIntA.pop_front();
	// 3 4 5 6
	//deqIntA.push_front(7);
	// 7 3 4 5 6
	//deqIntA.push_front(8);
	// 8 7 3 4 5 6

	//deqIntA.pop_back();
	// 8 7 3 4 5 
	//deqIntA.pop_back();
	// 8 7 3 4 

	//cout << "deqIntA �е�Ԫ��: " << endl;
	//for (unsigned int i = 0; i < deqIntA.size(); i++) {
	//	cout << deqIntA[i] << endl;
	//}

	system("pause");
	return 0;
}