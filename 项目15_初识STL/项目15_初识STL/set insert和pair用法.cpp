#include <set>
#include <iostream>
#include <functional>>
#include <algorithm>

using namespace std;

int main(void) {

	set<int> setInt;

	for (int i = 5; i > 0; i--) {
		pair<set<int>::iterator, bool> ret = setInt.insert(i);
		if (ret.second) {
			cout << "���� " << i << "�ɹ�! " << endl;
		}
		else {
			cout << "���� " << i << "ʧ��! " << endl;
		}
		setInt.insert(5);
	}
	

	cout << "max size: " << setInt.max_size() << endl;
	//bool ret = setInt.insert(5);  ���صĲ����ǲ�������

	/*cout << "��һ��: " << *(ret.first) << endl;
	cout << "�ڶ���: " << ret.second << endl;*/

	system("pause");
	return 0;
}