#include <iostream>

using namespace std;

//��һ��
int Max(int a, int b)
{
	cout << "���� int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	cout << "���� T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c) {
	cout << "���� T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);
}

//�ڶ���
int Max1(int a, int b)
{
	cout << "���� int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T1, typename T2>
T1 Max1(T1 a, T2 b)
{
	cout << "���� T Max1(T1 a, T2 b)" << endl;
	return a > b ? a : b;
}


void main(void) {
	int a = 1;
	int b = 2;


	//������ģ�����ͨ���������ϵ���ʱ,����ѡ����ͨ����
	//cout<<"Max(a, b)"<<Max(a, b)<<endl;

	//�����ʽ��ʹ�ú���ģ��,��ʹ��<> �����б�
	//Max<>(a, b);

	char c = 'a';
	//�������ģ���������õ�ƥ�䣬ʹ�ú���ģ��
	//Max1(c, a);
	//Max(1.0, 2.0);

	Max(3.0, 4.0, 5.0);

	system("pause");
	return;
}