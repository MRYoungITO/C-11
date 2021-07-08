#include <Windows.h>
#include <iostream>

#include "SizeFilter.hpp"

using namespace std;

int main(void) {

	sizeFilter<int> sf;

	for (int i = 0; i < 10; i++) {
		sf.insert(i * 5);
	}

	sf.erase(0);
	sf.erase(45);
	
	cout << "��ȡ���:" << endl;
	//��ȡ���ֵ
	pair<int, bool> pb1 = sf.getMax();
	if (pb1.second) {
		cout << "max: " << pb1.first << endl;
	}
	else {
		cout << "Not Found." << endl;
	}

	//��ȡ��Сֵ
	pair<int, bool> pb2 = sf.getMin();
	if (pb2.second) {
		cout << "min: " << pb2.first << endl;
	}
	else {
		cout << "Not Found." << endl;
	}

	system("pause");
	return 0;
}