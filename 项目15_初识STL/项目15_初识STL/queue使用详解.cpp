#include <queue>
#include <deque>
#include <set>
#include <list>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

int main(void) {
	//queue<int> queueInt;
	//queue<int, list<int>> queueList;  //list ������Ϊqueue����������
	////queue<int, vector<int>> queueVector;  //vector ������Ϊqueue����������
	//queueInt.push(1);
	//queueInt.push(2);
	//queueInt.push(3);
	//queueInt.push(4);
	//queueInt.push(5);
	//int iFront = queueInt.front();	//1
	//int iBack = queueInt.back();	//5
	//queueInt.front() = 66;
	//queueInt.back() = 88;
	//cout << "���׵�Ԫ����: " << queueInt.front() << endl;
	//cout << "��β��Ԫ����: " << queueInt.back() << endl;
	//int iSize = queueInt.size();  //iSize = 5;
	//if (!queueInt.empty()) {
	//	cout << "queueInt��Ԫ�ظ���: " << iSize << endl;
	//}
	//*queueInt.pop();
	//queueInt.pop();*/
	////cout << "���׵�Ԫ����: " << queueInt.front() << endl;

	//priority_queue<int> pqA;	//Ĭ���������ֵԽ��, ���ȼ�Խ��
	//priority_queue<int, vector<int>, greater<int>> pqA; //ʹ�� vectorֵԽС, ���ȼ�Խ��
	priority_queue<int, deque<int>, greater<int>> pqA;	//ʹ�� dequeֵԽС, ���ȼ�Խ��
	//priority_queue<int, list<int>, greater<int>> pqA;	//������ʹ�� list, ������
	

	pqA.push(1);
	pqA.push(2);
	pqA.push(3);
	pqA.push(3);
	pqA.push(3);
	pqA.push(4);
	pqA.push(5);
	pqA.push(3);

	while (!pqA.empty()) {
		cout << pqA.top() << " ";	//��ȡ���׵�Ԫ��, ��Ԫ�ز�����
		pqA.pop();					//������
	}
	cout << endl;

	system("pause");
	return 0;
}