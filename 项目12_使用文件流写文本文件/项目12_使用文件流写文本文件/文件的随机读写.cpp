#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// ����һ������, ����ָ���ļ��Ĵ�С
long long getSize(const char* fileName) {
	ifstream infile;
	infile.open(fileName);
	if (!infile.is_open()) {
		return 0;
	}
	infile.seekg(0, infile.end);
	long long ret = infile.tellg();
	infile.close();
	return ret;
}

int main(void) {
	//ifstream infile;
	//string line;
	/*
	infile.open("�ļ��������д.cpp");
	if (!infile.is_open()) {
		return 1;
	}*/
	cout << getSize("�ļ��������д.cpp") << endl;

	//seekg�÷�, �ļ�����β�����50λ����
	/*
	infile.seekg(-50, infile.end);
	while (!infile.eof()) {
		getline(infile, line);
		cout << line << endl;
	}*/

	//infile.close();
	system("pause");
	return 0;
}