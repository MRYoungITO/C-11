#include <map>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main(void) {
	map<int, string> mapStu;

	//��ʽһ ����һ��pair, Ȼ�����, ���������,�ͻ����ʧ��
	pair<map<int, string>::iterator, bool> ret = mapStu.insert(pair<int, string>(1, "����"));
	if (ret.second) {
		cout << "����ɹ�! value: " << (*(ret.first)).second << endl;
	}
	else {
		cout << "����ʧ��!" << endl;
	}

	ret = mapStu.insert(pair<int, string>(1, "С����"));
	if (ret.second) {
		cout << "����ɹ�! value: " << (*(ret.first)).second << endl;
	}
	else {
		cout << "����С����ʧ��!" << endl;
	}

	//��ʽ�� make_pair
	mapStu.insert(make_pair(2, "����"));

	//��ʽ�� ʹ��value_type, �൱��pair<int, sting>
	mapStu.insert(map<int, string>::value_type(3, "����"));

	//mapStu.insert(pair<int, string>(4, "����"));

	//��ʽ�� ֱ��ʹ��[]���أ� �����ֵ���Ѿ�����,�򸲸�ֵ
	mapStu[4] = "����";

	mapStu[5] = mapStu[6];
	mapStu[7] = mapStu[4];
	//multimap ��֧��[]����, map ֧��
	//mapStu[4] = "����";

	//multimap ֧����ͬ��key ����
	//mapStu.insert(pair<int, string>(3, "С����"));

	for (multimap<int, string>::iterator it = mapStu.begin(); it != mapStu.end(); it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}

	system("pause");
	return 0;
}