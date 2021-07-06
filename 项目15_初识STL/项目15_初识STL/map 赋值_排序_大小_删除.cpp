#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	map<int, string, less<int>> mapStu;

	mapStu.insert(pair<int, string>(2, "����"));
	mapStu.insert(pair<int, string>(1, "����"));
	mapStu.insert(pair<int, string>(3, "����"));
	mapStu.insert(pair<int, string>(4, "����"));

	map<int, string, greater<int>>::size_type ret = mapStu.erase(5);
	cout << "ret = " << ret << endl;

	/*int range[] = { 1,2,3,4 };
	mapStu.erase(range + 1, range + 3);*/ //ɾ������ָ���İ�հ뿪�������ض���key��Ӧ�����ж���
	map<int, string, less<int>>::iterator bit = mapStu.begin();
	map<int, string, less<int>>::iterator eit = mapStu.end();
	++bit;
	mapStu.erase(++bit, --eit);

	for (map<int, string, greater<int>>::iterator it = mapStu.begin(); it != mapStu.end(); it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}


	system("pause");
	return 0;
}