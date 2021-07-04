#include <set>
#include <iostream>
#include <functional>>
#include <algorithm>

using namespace std;

int main(void) {
		
	set<int> setInt;

	setInt.insert(1);
	setInt.insert(2);
	setInt.insert(3);
	setInt.insert(4);
	setInt.insert(5);
	setInt.insert(6);

	set<int>::iterator it1 = setInt.find(4);
	int elem1 = *it1;
	cout << "elem1: " << elem1 << endl;

	it1 = setInt.find(8);

	if (it1 != setInt.end()) {//find �Ƿ���ҵ�Ԫ��, ����ͨ����������������end()���бȽ�
		int elem2 = *it1;
		cout << "elem2: " << elem2;
	}
	else {
		cout << "8 ������." << endl;
	}

	int icount = setInt.count(3);  //icount == 1
	cout << "count(3) = " << icount << endl;

	set<int>::iterator it2 = setInt.lower_bound(3);
	set<int>::iterator it3 = setInt.upper_bound(3);
	int elem2 = *it2;  //elem2 == 3
	int elem3 = *it3;  //elem3 == 4
	cout << "elem2: " << elem2 << endl;
	cout << "elem3: " << elem3 << endl;

	pair<set<int>::iterator, set<int>::iterator> ii = setInt.equal_range(3);
	cout << "equal_range(3)���صĵ�һ����������ֵ: " << *(ii.first) << endl;
	cout << "equal_range(3)���صĵڶ�����������ֵ: " << *(ii.second) << endl;

	//for (int i = 0; i < 6; i++) {
	//	setInt.insert(i + 1);
	//}

	//set<int>::iterator itBegin = setInt.begin();
	//++itBegin;
	//set<int>::iterator itEnd = setInt.begin();
	//++itEnd;
	//++itEnd;
	//++itEnd;
	//setInt.erase(itBegin, itEnd);

	////ɾ�������е�һ��Ԫ��
	//setInt.erase(setInt.begin()); //4 5 6

	////ɾ��������ֵΪ5��Ԫ��
	//setInt.erase(5);  //4 6

	////ɾ�����������е�Ԫ��
	//setInt.clear();

	//for (set<int>::iterator it = setInt.begin(); it != setInt.end(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	system("pause");
	return 0;
}