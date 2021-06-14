#include <iostream>
#include <Windows.h>

using namespace std;
class Father
{
public:
	virtual void func1() { cout << "Father::func1" << endl; }
	virtual void func2() { cout << "Father::func2" << endl; }
	virtual void func3() { cout << "Father::func3" << endl; }
	void func4() { cout << "���麯��: Father::func4" << endl; }
public:
	int x = 200;
	int y = 300;
	static int z;
};

class Son : public Father {
public:
	void func1() { cout << "Son::func1" << endl; }
	virtual void func5() { cout << "Son::func5" << endl; }
};

int Father::z = 0;

typedef void(*func_t)(void);  

int main(void) {
	/*Father father;

	cout << "sizeof(father)==" << sizeof(father) << endl;

	cout << "�����ַ:" << (int*)&father << endl;
	int* vptr = (int*)*(int*)(&father);

	cout << "���õ�һ���麯��: ";
	((func_t) * (vptr + 0))();

	cout << "���õڶ����麯��: ";
	((func_t) * (vptr + 1))();

	cout << "���õ������麯��: ";
	((func_t) * (vptr + 2))();

	cout << "��һ�����ݳ�Ա�ĵ�ַ: " << endl;
	cout << &father.x << endl;
	cout << std::hex << (int)&father + 4 << endl;
	cout << "��һ�����ݳ�Ա��ֵ: " << endl;
	cout << std::dec << father.x << endl;
	cout << *(int*)((int)&father + 4) << endl;

	cout << "�ڶ������ݳ�Ա�ĵ�ַ: " << endl;
	cout << &father.y << endl;
	cout << std::hex << (int)&father + 8 << endl;
	cout << "�ڶ������ݳ�Ա��ֵ: " << endl;
	cout << std::dec << father.y << endl;
	cout << *(int*)((int)&father + 8) << endl;*/

	//Son son;
	//cout << "son�����ַ: " << (int*)&son << endl;  //(int*) ��ָ��16���Ʒ�ʽ��ӡ����
	//int* vptr = (int*)*(int*)&son;
	//cout << "�麯����ָ��vptr: " << vptr << endl;

	//for (int i = 0; i < 4; i++) {
	//	cout << "���õ�" << i + 1 << "���麯��: ";
	//	((func_t) * (vptr + i))();
	//}

	//for (int i = 0; i < 2; i++) {
	//	cout << *(int*)((int)&son + 4 + i * 4) << endl;
	//}

	//cout << "sizeof(son) == " << sizeof(son) << endl;

	Son son;
	Father* father = &son;
	father->func1();

	system("pause");
	return 0;
}