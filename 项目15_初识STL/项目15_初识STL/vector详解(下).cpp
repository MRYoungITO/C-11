#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

void demo1() {
	//vector ���ι��캯��
	//vector<int> v2(10);  //����ʱ�ͷ���ռ�, ͬʱ����10��Ԫ��,Ԫ�ش�СΪ0
	vector<int> v2(10, 666);
	//vector<int> v3(v2);
	//vector<int> v3(v2.begin() + 3, v2.end());
	int test[] = { 1,2,3,4,5 };
	vector<int> v3(test, test + 5);

	cout << "v2 ��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2 �����Ĵ�С: " << v2.capacity() << endl;

	//vector ��ɾ��
	//1. ������vector ���ɵ�
	/*v2.clear();
	cout << "���� v2.clear() ��" << endl;
	cout << "v2 ��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2 �����Ĵ�С: " << v2.capacity() << endl;*/

	//2.�ɵ�����Ԫ��
	//v2[1] = 888;
	//v2.erase(v2.begin() + 1);

	//3.�ɵ����Ԫ��
	v2.erase(v2.begin(), v2.begin() + 3);

	cout << "v2 ��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2 �����Ĵ�С: " << v2.capacity() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}

	//v2.push_back(888);  //int &&_val - ��ֵ���� C++11��������
	//cout << "v2 ��Ԫ�ظ���: " << v2.size() << endl;
	//cout << "v2 �����Ĵ�С: " << v2.capacity() << endl;

	//���µ���vector �Ĵ�С
	//v2.resize(2, 999);  //��һ�ַ�ʽ: ���¶����С
	//v2.resize(13, 888);  //�ڶ��ַ�ʽ: ���¶����С,����ʱָ��������ֵ
	//v2.resize(13);  //�����ַ�ʽ: ���¶����С,����ʱ��ָ��������ֵ.�����ӵ�Ĭ��ֵ��0

	//cout << "v2 ��Ԫ�ظ���: " << v2.size() << endl;
	//cout << "v2 �����Ĵ�С: " << v2.capacity() << endl;
	//cout << "�����е�ֵ: " << endl;
	//for (int i = 0; i < v2.size(); i++) {
	//	cout << v2[i] << endl;
	//}
	//cout << "---end---" << endl;

	//vector<int> v4;
	//if (v4.empty()) {
	//	cout << "v4 Ϊ��!" << endl;
	//}

	//β����Ӻ�ɾ��Ԫ��
	//v2.push_back(999);
	/*v2.pop_back();
	cout << "v2β��ɾ��һ��Ԫ��" << endl;
	cout << "v2 ��Ԫ�ظ���: " << v2.size() << endl;
	cout << "v2 �����Ĵ�С: " << v2.capacity() << endl;*/

	//��һ ʹ���±����
	//�ڶ� ʹ��at
	//���� �ӿڷ��ص�����
	//��һ�ֺ͵ڶ��ַ�ʽ����ע��Խ��
	//cout << "v2 �е�Ԫ��: " << endl;
	//v2[0] = 555;
	/*v2.front() = 555;
	v2.back() = 999;
	v2.at(2) = 777;*/

	//vector �Ĳ���
	//���뵥��Ԫ��
	//vector<int>::iterator it = v2.insert(v2.begin(), 888);
	//for (; it!=v2.end(); it++) {
	//	cout << *it << endl;
	//}
	//cout << "-----------------" << endl;
	//������Ԫ��
	//v2.insert(v2.begin(), 3, 888);
	//v2.insert(v2.begin() + 3, v3.begin(), v3.end());

	//for (int i = 0; i < v2.size(); i++) {
	//	cout << v2.at(i) << endl;
	//}

	/*cout << "v2 ��һ��Ԫ��: " << v2.front() << endl;
	cout << "v2 ���һ��Ԫ��: " << v2.back() << endl;*/

	//��ת�ĵ�����
	cout << "������� v3:" << endl;
	vector<int>::reverse_iterator it = v3.rbegin();
	for (; it != v3.rend(); it++) {
		cout << *it << endl;
	}

	/*vector<int>::const_iterator it1 = */v2.cbegin();
	vector<int>::const_iterator it = v2.begin();
}

int main(void) {
	demo1();

	system("pause");
	return 0;
}