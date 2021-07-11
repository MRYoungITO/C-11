#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int demo1() {
	/*static*/ int i = 0;
	
	//printf("i �ĵ�ַ: %p, i=%d\n", &i, i);

	return i;
}

int& demo(int** addr) {
	/*static*/ int i = 666;
	*addr = &i;
	printf("i �ĵ�ַ: %p, i=%d\n", &i, i);
	return i;
}

int& demo_static(int** addr) {
	static int i = 666;
	*addr = &i;
	printf("i �ĵ�ַ: %p, i=%d\n", &i, i);
	return i;
}

//3. ���������β�(��ͨ����)������
int& demo3(int var) {
	var = 666;
	return var;
}

//4. ���������β�(����)������
int& demo4(int& var) {
	var = 666;
	return var;
}

int main(void) {
	int* addr = NULL;
	int ret = demo(&addr);

	//��һ����� �������ؾֲ��������ò��ܳ�Ϊ�������õĳ�ʼֵ
	//int& i1 = demo(&addr);
	/*int i1 = 888;
	printf("addr: %p, i1=%d\n", addr, i1);*/

	//demo(&addr);
	/*demo1();
	printf("addr: %p, i1=%d\n", addr, i1);*/

	//�ڶ������ �������ؾֲ�����������Ϊ��ֵ
	/*demo(&addr) = 888;
	printf("addr: %p, value: %d\n", addr, *addr);
	demo1();
	printf("addr: %p, value: %d\n", addr, *addr);*/

	//��������� ���ؾ�̬������ȫ�ֱ������Գ�Ϊ��ֵ�����������õĳ�ʼֵ
	//demo_static(&addr) = 888;
	int& i1 = demo_static(&addr);
	i1 = 888;
	printf("1. addr: %p, value: %d\n", addr, *addr);
	demo1();
	printf("2. addr: %p, value: %d\n", addr, *addr);
	demo_static(&addr); 
	
	system("pause");
	return 0;
}