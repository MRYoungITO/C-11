#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

void demo1() {
	//vector �����Ĭ�Ϲ���
	//vector<int> v1;
	//vector<float> v2;

	//cout << "v1 �Ĵ�С: " << v1.size() << endl;
	//cout << "v1 �����Ĵ�С: " << v1.capacity() << endl;

	//������ʹ��vector ��Ĭ�Ϲ��캯��ʱ, �м�, ����ֱ��ͨ���±�ȥ����
	//v1[0] = 1;

	//v1.push_back(1);
	//cout << "β������1��Ԫ�غ�: " << endl;
	//cout << "v1 ��Ԫ�ظ���: " << v1.size() << endl;
	//cout << "v1 �����Ĵ�С: " << v1.capacity() << endl;
	//v1.push_back(2);
	//v1.push_back(3);
	//v1.push_back(4);
	//v1.push_back(5);

	//cout << "β������5��Ԫ�غ�: " << endl;
	//cout << "v1 ��Ԫ�ظ���: " << v1.size() << endl;
	//cout << "v1 �����Ĵ�С: " << v1.capacity() << endl;

	//vector ���ι��캯��
	//vector<int> v2(10);  //����ʱ�ͷ���ռ�, ͬʱ����10��Ԫ��,Ԫ�ش�СΪ0
	vector<int> v2(10, 666);
	//vector<int> v3(v2);
	//vector<int> v3(v2.begin() + 3, v2.end());
	int test[] = { 1,2,3,4,5 };
	vector<int> v3(test, test + 2);

	cout << "v2 ��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2 �����Ĵ�С: " << v2.capacity() << endl;

	//vector �ĸ�ֵ
	v2[0] = 1;
	v2[1] = 2;

	//v2.assign(2, 888); //��һ���淨  �ı�ԭ��vector�е�Ԫ�ظ�����ֵ
	//v2.assign(v3.begin(), v3.end()); //�ڶ����淨, ʹ�õ�������ֵ
	int test1[] = { 1,2,3,4,5 };
	//v2.assign(test1, test1 + 3); //�������淨, ʹ��ָ�븳ֵ
	v2 = v3;

	cout << "v2���� assign ��: " << endl;
	cout << "v2 �д洢��Ԫ����: " << endl; 
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}

	cout << "v3 �д洢��Ԫ����: " << endl;
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << endl;
	}
}

int main(void) {
	demo1();

	system("pause");
	return 0;
}