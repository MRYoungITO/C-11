#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	ifstream stream;
	int max, min, s = 0;
	int num;  // ÿ�ζ�������
	int n = 0;
	stream.open("num.txt");
	if (!stream.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		exit(1);
	}

	stream >> num;
	max = num;
	min = num;
	s += num;
	n++;

	while (1) {
		stream >> num;
		if (stream.eof()) {
			break;
		}

		n++;
		s += num;
		if(num > max) {
			max = num;
		}
		else if (num < min) {
			min = num;
		}
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	cout << "average = " << s / n << endl;
	cout << "n = " << n << endl;

	stream.close();
	system("pause");
	return 0;
}