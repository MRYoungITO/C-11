#include <iostream>
#include <Windows.h>

using namespace std;

void demo(const char* p) {

	//��ָ��ȥ��const
	//char* p1 = const_cast<char*>(p);
	//p1[0] = 'A';

	//ֱ��ȥ��const�޸�
	const_cast<char*>(p)[0] = 'A';

	cout << p << endl;
}

//void demo(const int p) {
//	cout << p << endl;
//}

int main(void) {

	//�ַ�������
	/*char p[] = "12345678";
	demo(p);*/  //�������

	//�����ַ�������ȥ��const �޸�
	//��ȥ�������޶���֮ǰ, ��ָ֤����ָ����ڴ��ܹ��޸�, �����޸���������쳣
	const char* cp = "987654321";
	demo(cp);

	system("pause");
	return 0;
}