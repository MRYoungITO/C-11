#include <iostream>
#include <deque>
#include <Windows.h>
using namespace std;

int main(void) {
	deque<int> deqIntA;
	//deque<int> deqIntB;

	deqIntA.push_back(1);
	deqIntA.push_back(2);
	deqIntA.push_back(3);
	deqIntA.push_back(4);
	deqIntA.push_back(5);

	// ��ʽһ ����ʹ�ò����Ľӿ�
	//deqIntA.erase(deqIntA.begin() + 1); //�ɵ��ڶ�����Ԫ�� 1 3 4 5

	//deqIntA.erase(deqIntA.begin() + 1, deqIntA.begin() + 3); //�ɵ�3 4, ʣ��1 5

	//deqIntA.clear(); //�ɵ����е�Ԫ��

	//��ʽ�� ʹ�õ���������ɾ��
	for (deque<int>::iterator it = deqIntA.begin(); it != deqIntA.end();) {
		if (*it == 4) {
			it = deqIntA.erase(it);
		}
		else {
			cout << *it;
			cout << " ";
			it++;
		}
	}
	cout << endl;

	//deqIntB.push_back(11);
	//deqIntB.push_back(12);
	//deqIntB.push_back(13);
	//deqIntB.push_back(14);

	//deqIntA.insert(deqIntA.begin(), 0); // 0 1 2 3 4
	//deqIntA.insert(deqIntA.begin() + 1, 2, 88); //0 88 88 1 2 3 4
	//deqIntA.insert(deqIntA.begin(), deqIntB.rbegin(), deqIntB.rend()); //11 12 13 14 0 88 88 1 2 3 4

	/*for (deque<int>::iterator it = deqIntA.begin(); it != deqIntA.end(); it++) {
		cout << *it;
		cout << " ";
	}
	cout << endl;*/

	system("pause");
	return 0;
}