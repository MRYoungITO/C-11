#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

int main(void) {
	ifstream inFile;
	string name;
	int age;

	// �Զ��ķ�ʽ���ļ�
	inFile.open("user.txt");
	while (1) {
		// ������
		inFile >> name;
		if (inFile.eof()) {
			break;
		}
		cout << name << "\t";

		// ������
		inFile >> age;
		cout << age << endl;
	}

	inFile.close();
	system("pause");
	return 0;
}