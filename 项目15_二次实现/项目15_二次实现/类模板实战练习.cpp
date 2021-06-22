#include <iostream>
#include <Windows.h>
#include "Vector.cpp"
using namespace std;

int main(void) {
	Vector<int> myVector(10);
	for (int i = 0; i < myVector.getLength(); i++) {
		myVector[i] = i;
	}

	for (int i = 0; i < myVector.getLength(); i++) {
		cout << myVector[i] << endl;
	}

	Vector<int> myIntVector1(myVector);
	cout << "�µ�myIntVector1�е�Ԫ������: " << endl;
	for (int i = 0; i < myIntVector1.getLength(); i++) {
		cout << myIntVector1[i] << endl;
	}
	cout << "---end---" << endl;

	Vector<int> myIntVector2(1);
	myIntVector2 = myIntVector1;
	cout << "�µ�myIntVector2�е�Ԫ������: " << endl;
	for (int i = 0; i < myIntVector2.getLength(); i++) {
		cout << myIntVector2[i] << endl;
	}
	cout << "---end---" << endl;

	Vector<float> myVector1(10);
	for (int i = 0; i < myVector1.getLength(); i++) {
		myVector1[i] = i * 0.1f;
	}

	for (int i = 0; i < myVector1.getLength(); i++) {
		cout << myVector1[i] << endl;
	}
}