#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	map<int, string> mapStu;

	mapStu.insert(pair<int, string>(2, "����"));
	mapStu.insert(pair<int, string>(1, "����"));
	mapStu.insert(pair<int, string>(3, "����"));
	mapStu.insert(pair<int, string>(4, "����"));

	multimap<int, string> mmapTeacher; //<�༶, ��ʦ>

	mmapTeacher.insert(pair<int, string>(101, "����ʦ"));
	mmapTeacher.insert(pair<int, string>(101, "����ʦ"));
	mmapTeacher.insert(pair<int, string>(102, "����ʦ"));
	mmapTeacher.insert(pair<int, string>(102, "����ʦ"));

	//multimap �Ĳ���
	int count = mmapTeacher.count(101);
	multimap<int, string>::iterator mit = mmapTeacher.find(101);
	if (mit != mmapTeacher.end()) { //�ҵ���
		//���multimap �е�ͬһ���Ķ��ֵ��
		//����һ ͨ���Ƚ�key, ѭ���ж�   �Ƽ�ʹ��
		for (; mit != mmapTeacher.end(); mit++) {
			if (mit->first == 101) {
				cout << "mmapTeacher.find(101) = " << mit->second << endl;
			}
			else {
				break;
			}
		}
	}
	else { //û�ҵ�
		cout << "�Ҳ�����ֵΪ101�ļ�ֵ��!" << endl;
	}

	//������ ͨ��count����������
	/*for (int i = 0; i < count; i++, mit++) {
		cout << "mmapTeacher.find(101) = " << mit->second << endl;
	}*/
	
	/*for (; mit != mmapTeacher.end(); mit++) {
		cout << "key: " << mit->first << " value: " << mit->second << endl;
	}*/

	//map �Ĳ���
	map<int, string>::iterator it = mapStu.find(3);
	if (it != mapStu.end()) { //�ҵ���
		cout << "mapStu.find(3)" << it->second << endl;
	}
	else { //û�ҵ�
		cout << "�Ҳ�����ֵΪ3�ļ�ֵ��!" << endl;
	}

	////equal_range �÷�
	//pair<multimap<int, string>::iterator, multimap<int, string>::iterator> mmiit = mmapTeacher.equal_range(101);
	//
	////��һ��������, ��Ӧbegin()
	//if (mmiit.first != mmapTeacher.end()) {
	//	cout << "mmapTeacher.find(101).begin = " << (*mmiit.first).second << endl;
	//}
	//
	////�ڶ���������, ��Ӧend()
	//if (mmiit.second != mmapTeacher.end()) {
	//	cout << "mmapTeacher.find(101).end = " << (*mmiit.second).second << endl; 
	//}

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> mmiit = mmapTeacher.equal_range(101);

	if (mmiit.first != mmapTeacher.end()) {
		cout << "mmapTeacher.find(101).begin = " << (*mmiit.first).second << endl;
	}

	if (mmiit.second != mmapTeacher.end()) {
		cout << "mmapTeacher.find(101).end = " << (*mmiit.second).second << endl;
	}
	for (map<int, string, greater<int>>::iterator it = mapStu.begin(); it != mapStu.end(); it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}


	system("pause");
	return 0;
}