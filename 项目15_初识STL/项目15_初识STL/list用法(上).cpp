#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>

using namespace std;

int main(void) {

	//vector<int> vectInt;
	//list<int> lstInt(10, 666);

	////vector ���ڴ�ռ���Ԥ�ȷ����
	//vectInt.capacity();

	////list ������capacity����, ��������û����ǰ����ռ�
	//cout << "lstInt size: " << lstInt.size() << endl;

	//for (list<int>::iterator it = lstInt.begin(); it != lstInt.end(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	////listͷβ������Ƴ�����
	//list<int> lstInt;
	//lstInt.push_back(1);
	//lstInt.push_back(2);
	//lstInt.push_back(3);
	//lstInt.push_back(4);
	//lstInt.push_back(5);

	//lstInt.pop_front();
	//lstInt.pop_front();

	////ǰ�����
	//lstInt.push_front(11); // 11 3 4 5
	//lstInt.push_front(12); // 12 11 3 4 5

	//lstInt.pop_back(); // 12 11 3 4
	//lstInt.pop_back(); // 12 11 3

	//list�����ݴ�ȡ
	list<int> lstInt;
	lstInt.push_back(1);
	lstInt.push_back(2);
	lstInt.push_back(3);
	lstInt.push_back(4);
	lstInt.push_back(5);

	int iFront = lstInt.front(); // 1
	int iBack = lstInt.back(); // 5

	lstInt.front() = 11; //��һ��Ԫ�ؾ͸�Ϊ11
	lstInt.back() = 19; //���һ��Ԫ�ؾ͸�Ϊ19

	for (list<int>::iterator it = lstInt.begin(); it != lstInt.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}