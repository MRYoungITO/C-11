#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
 
void Swap(T& a, T& b) {
	T t;
	t = a;
	a = b;
	b = t;
	cout << "Swap ģ�庯����������" << endl;
}

//void Swap(char& a, int& b) {
//	int t;
//	t = a;
//	a = b;
//	b = t;
//	cout << "Swap ��ͨ������������" << endl;
//}

int main(void) {
	char cNum = 'c';
	int iNum = 65;

	// ��һ����� ģ�庯������ͨ��������, �������ͺ���ͨ���غ�����ƥ��
	// ������ͨ����
	//Swap(cNum, iNum);

	//�ڶ������ ������ͨ����, ����ģ�����ʽ��������ת����?
	// ����: ���ṩ��ʽ����������ת��, �������ϸ��ƥ��
	//Swap(cNum, iNum);

	system("pause");
	return 0;
}