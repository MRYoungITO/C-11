#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
	string name;
	int age;

	ofstream outfile;
	outfile.open("user.dat", ios::out | ios::binary | ios::trunc);

	while (1) {
		cout << "����������[Ctrl+Z�˳�]: ";
		cin >> name;
		if (cin.eof()) {
			break;
		}
		outfile << name << "\t";

		cout << "����������: ";
		cin >> age;
		outfile.write((char*)&age, sizeof(age));
	}

	system("pause");
	return 0;
}