#include <Windows.h>
#include "Boy.h"
#include "Girl.h"
#include <iostream>
#include <vector>

void autoPair(const vector<Boy>& boys, const vector<Girl>& girls) {
	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {
				cout << boys[i].description() << "<==> " << girls[j].description() << endl;
			}
		}
	}
}

int main(void) {
	vector<Boy> boys;
	vector<Girl> girls;

	Boy::inputBoys(boys);
	Girl::inputGirls(girls);

	cout << "\n------------------���------------------\n\n";
	autoPair(boys, girls);

	system("pause");
	return 0;
}

/*
����������
25 ��� 15000
28 ���� 8000
35 ���� 50000
0
18 С��Ů 95
25 �绨 79
26 ���� 90
26 ��Ī�� 100
0
*/