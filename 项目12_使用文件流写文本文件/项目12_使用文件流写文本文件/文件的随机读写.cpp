#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*
*�������ļ�д��: "123456789"
* Ȼ�����ڵ�4���ַ�λ��д��"ABC"
*/

int main(void) {
	ofstream outfile;

	outfile.open("test.txt");
	if (!outfile.is_open()) {
		return 1;
	}

	outfile << "123456789";
	outfile.seekp(4, outfile.beg);
	outfile << "ABC";

	outfile.close();
	system("pause");
	return 0;
}

/*
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

	cout << getSize("�ļ��������д.cpp") << endl;

	system("pause");
	return 0;
}*/


/*
int main(void) {

	ifstream infile;
	string line;

	infile.open("�ļ��������д.cpp");
	if (!infile.is_open()) {
	return 1;
	}

	//seekg�÷�, �ļ�����β�����50λ����
	
	infile.seekg(-50, infile.end);
	while (!infile.eof()) {
		getline(infile, line);
		cout << line << endl;
	}

	infile.close();
	system("pause");
	return 0;
}*/