#include <map>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main(void) {
	multimap<int, string> mapStu;

	mapStu.insert(pair<int, string>(1, "����"));
	mapStu.insert(pair<int, string>(2, "����"));
	mapStu.insert(pair<int, string>(3, "����"));

	//multimap ��֧��[]����, map ֧��
	//mapStu[4] = "����";

	//multimap ֧����ͬ��key ����
	mapStu.insert(pair<int, string>(3, "С����"));

	for (multimap<int, string>::iterator it = mapStu.begin(); it != mapStu.end(); it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}

	system("pause");
	return 0;
}