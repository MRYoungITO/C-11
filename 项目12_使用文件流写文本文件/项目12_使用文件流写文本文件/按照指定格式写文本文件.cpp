#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <sstream>  //stirngfstream

using namespace std;

int main(void) {
	string name;
	int age;
	ofstream outfile;
	outfile.open("user.txt");
	while (1) {
		cout << "����������[Ctrl+Z�˳�]: ";
		cin >> name;
		if (cin.eof()) {
			break;
		}
		cout << "����������: ";
		cin >> age;

		stringstream s;
		s << "����:" << name << "\t\t\t����: " << age << endl; 

		// ��ָ����ʽ������д���ļ�
		outfile << s.str();
	}
	outfile.close();
	system("pause");
	return 0;
}