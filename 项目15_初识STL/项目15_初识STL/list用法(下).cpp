#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>

using namespace std;

int main(void) {
	//list<int> lstIntA, lstIntB, lstIntC, lstIntD;
	//lstIntA.push_back(1);
	//lstIntA.push_back(3);
	//lstIntA.push_back(5);
	//lstIntA.push_back(7);
	//lstIntA.push_back(9);

	////lstIntB.assign(lstIntA.begin(), lstIntA.end());	// 1 3 5 7 9

	////ʹ��ǰ��++ ��--
	//lstIntB.assign(++lstIntA.begin(), --lstIntA.end()); // 3 5 7  ע��: ǰ�����
	//lstIntC.assign(5, 8);								// 8 8 8 8 8
	//lstIntD = lstIntA;								// 1 3 5 7 9
	//lstIntC.swap(lstIntD);							// ����


	//list ����Ԫ��
	//list<int> listA;
	//list<int> listB;

	//listA.push_back(1);
	//listA.push_back(2);
	//listA.push_back(3);
	//listA.push_back(4);
	//listA.push_back(5);

	//listB.push_back(11);
	//listB.push_back(12);
	//listB.push_back(13);
	//listB.push_back(14);

	//listA.insert(listA.begin(), -1);		//{-1, 1, 2, 3, 4, 5}
	//listA.insert(++listA.begin(), 2, -2);	//{-1, -2, -2, 1, 2, 3, 4, 5}
	//listA.insert(listA.begin(), ++listB.begin(), --listB.end());	//{11, 12, 13, 14, -1, -2, -2, 1, 2, 3, 4, 5}

	//vector<int> vectA;
	//vector<int> vectB;
	//vectA.insert(vectA.begin(), vectB.begin() + 2, --vectB.end());

	//list ɾ��Ԫ��
	//list<int> listA;

	//listA.push_back(1);
	//listA.push_back(2);
	//listA.push_back(3);
	//listA.push_back(4);
	//listA.push_back(5);

	////erase ���÷�
	//list<int>::iterator itBegin = listA.begin();
	//++itBegin;
	//list<int>::iterator itEnd = listA.begin();
	//++itEnd;
	//++itEnd;
	//++itEnd;
	//listA.erase(itBegin, itEnd);//��ʱ����lstInt������˳���1, 4, 5����Ԫ�ء�

	//listA.erase(listA.begin());
	//listA.push_back(4); // 4 5 4
	//listA.insert(listA.end(), 5, 4); //4 5 4 4 4 4 4 4

	////remove ɾ��Ԫ��
	////��ʽһ ֱ�ӵ���remove
	////listA.remove(4);

	////��ʽ�� ����Ȼ��ɾ��
	//for (list<int>::iterator it = listA.begin(); it != listA.end();) {
	//	if (*it == 4) {
	//		it = listA.erase(it); // �൱��ִ�п�++;
	//	}
	//	else {
	//		++it;
	//	}
	//}

	//list ����Ԫ��
	list<int> listA;

	listA.push_back(1);
	listA.push_back(2);
	listA.push_back(3);
	listA.push_back(4);
	listA.push_back(5);

	listA.reverse();

	for (list<int>::iterator it = listA.begin(); it != listA.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}