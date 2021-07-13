#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

int main1(void) {

	//�׶�1. auto_ptr ��C++11��������Ҫ���� p1 = p2, ���ƻ�ֵ����ı���Դ������Ȩ
	auto_ptr<string>p1(new string("I'm martin"));
	auto_ptr<string>p2(new string("I'm Rock"));
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());

	p1 = p2;

	printf("after p1 = p2\n");
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());

	// �׶�2. �� STL ������ʹ��auto_ptr�����ش����, ��Ϊ�����ڵ�Ԫ�ر���֧�ֿɸ���(copyconstructable)�Ϳɸ�ֵ(assignable)
	vector<auto_ptr<string>> va;
	auto_ptr<string>p3(new string("I'm p3"));
	auto_ptr<string>p4(new string("I'm p4"));

	va.push_back(std::move(p3));
	va.push_back(std::move(p4));

	cout << "va[0]: " << *va[0] << endl;
	cout << "va[1]: " << *va[1] << endl;

	//��������
	va[0] = va[1];
	cout << "va[0]: " << *va[0] << endl;
	cout << "va[1]: " << *va[1] << endl;

	//�׶�3. ��֧�ֶԶ���������ڴ����
	//auto_ptr<int[]>ai(new int[5]);  //������������

	//auto_ptr ����, ���ܰ�ͬһ���ڴ潻�����auto_ptr ����ȥ����
	/*{
		auto_ptr<string>p2;

		string* str = new string("����ָ����ڴ��������");
		p2.reset(str);
		{
			auto_ptr<string>p1;
			p1.reset(str);
		}
		cout << "str: " << *p2 << endl;
	}*/
	
	system("pause");
	return 0;
}

int main(void) {

	//�׶�1. auto_ptr ��C++11��������Ҫ���� p1 = p2, ���ƻ�ֵ����ı���Դ������Ȩ
	//unique_ptr ��ν���������? ��������ʽ����ֵ��ֵ�͹���
	unique_ptr<string>p1(new string("I'm martin"));
	unique_ptr<string>p2(new string("I'm Rock"));
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());

	//���һ��Ҫת��, ʹ��move����ֵת����ֵ
	p1 = std::move(p2);
	printf("p1: %p\n", p1.get());
	printf("p2: %p\n", p2.get());
	//p1 = p2;  //��ֵ��ֵ��ֹ
	unique_ptr<string>p3(new string("I'm martin"));
	unique_ptr<string>p4(std::move(p3));  //��ֵ��������Ҳ����, ����ת����ֵ

	// �׶�2. �� STL ������ʹ��auto_ptr�����ش����, ��Ϊ�����ڵ�Ԫ�ر���֧�ֿɸ���(copyconstructable)�Ϳɸ�ֵ(assignable)
	vector<unique_ptr<string>> vu;
	unique_ptr<string>p5(new string("I'm p3"));
	unique_ptr<string>p6(new string("I'm p4"));

	vu.push_back(std::move(p5));
	vu.push_back(std::move(p6));

	cout << "v0[0]: " << *vu[0] << endl;
	cout << "v0[1]: " << *vu[1] << endl;

	//��������
	/*va[0] = va[1];  //��֧��ֱ�Ӹ�ֵ, û�з���
	cout << "va[0]: " << *va[0] << endl;
	cout << "va[1]: " << *va[1] << endl;*/

	//�׶�3. auto_ptr��֧�ֶԶ���������ڴ����
	//����unique_ptr ֧�ֶ�������Ĺ���
	//auto_ptr<int[]>ai(new int[5]);  //������������
	unique_ptr<int[]>ui(new int[5]);  //�Զ������delete [] ����ȥ�ͷ�

	//auto_ptr ����, ���ܰ�ͬһ���ڴ潻�����auto_ptr ����ȥ����
	/*{
		auto_ptr<string>p2;

		string* str = new string("����ָ����ڴ��������");
		p2.reset(str);
		{
			auto_ptr<string>p1;
			p1.reset(str);
		}
		cout << "str: " << *p2 << endl;
	}*/

	system("pause");
	return 0;
}