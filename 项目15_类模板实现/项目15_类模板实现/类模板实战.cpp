#include <iostream>
#include <Windows.h>
#include "Vector.cpp"
using namespace std;

int main() {
	Vector<int> myVector(10);
	// int a[10];  len: sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < myVector.getLength(); i++) {
		myVector[i] = i;
	}

	for (int i = 0; i < myVector.getLength(); i++) {
		cout << myVector[i] << endl;
	}

	// ���Կ������캯��
	Vector<int> myIntVector1(myVector);
	cout << "�µ�myIntVector1�е�Ԫ������: " << endl;
	for (int i = 0; i < myIntVector1.getLength(); i++) {
		cout << myIntVector1[i] << endl;
	}
	cout << "---end---" << endl;

	// ���Ը�ֵ���������
	Vector<int> myIntVector2(1);
	myIntVector2 = myIntVector1;

	cout << "�µ�myIntVector2�е�Ԫ������: " << endl;
	for (int i = 0; i < myIntVector2.getLength(); i++) {
		cout << myIntVector2[i] << endl;
	}
	cout << "---end---" << endl;

	Vector<float> myVector1(10);
	// int a[10];  len: sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < myVector1.getLength(); i++) {
		myVector1[i] = i * 0.1f;
	}

	for (int i = 0; i < myVector1.getLength(); i++) {
		cout << myVector1[i] << endl;
	}

	system("pause");
	return 0;
}