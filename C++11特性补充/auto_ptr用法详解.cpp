#include <iostream>
#include <Windows.h>
#include <string>
#include <memory>
#include <exception>

using namespace std;

//auto_ptr<Test> t(new Test());  //�Ҹ�1: ����ָ�벻Ҫ����Ϊȫ�ֱ���

class Test {
public:
	Test() {
		cout << "Test is contrust" << endl;
		debug = 1;
	}
	~Test() { cout << "Test is detrust" << endl; }

	int getDebug() {
		return debug;
	}

private:
	int debug;
};

// �÷�: auto_ptr<����> ������(new ����)

void memory_leak_demo1() {
	auto_ptr<Test> t(new Test());  //����ָ�� C-98, д��

	//�Ҹ�3: �����Լ�֪�����, ��Ҫ��ayto_ptr ����ָ�븳ֵ��ͬ���͵�����һ������ָ�� 
	//auto_ptr<Test> t1;
	//t1 = t;

	//auto_ptr<Test>* tp = new auto_ptr<Test>(new Test()); //�Ҹ�2: ��Ҫ����ָ������ָ������ָ�����

	//��ʹ������ָ����ʶ���ʱ, ʹ�÷�ʽ����ָͨ��һ��
	cout << "-> debug: " << t->getDebug() << endl;
	cout << "* debug: " << (*t).getDebug() << endl;

	/*Test* tmp = t.get();
	cout << "get debug: " << tmp->getDebug() << endl;*/

	//release ȡ��ָ��Զ�̬�ڴ���й�, ֮ǰ������ڴ�����ֶ��ͷ�
	/*Test* tmp = t.release();
	delete tmp;*/

	//reset ��������ָ���йܵ��ڴ��ַ, �����ַ��һ��, ԭ���Ļᱻ����
	//t.reset();
	t.reset(new Test());

	if (0) {
		Test* t1 = new Test();
		t1->getDebug();
	}

	return;
}

int memory_leak_Demo2() {
	auto_ptr<Test> t(new Test());
	//Test* t = new Test();

	/*****************************************
	* ����ִ��һ�θ��ӵ��߼�, �����һ���������
	* ���ļ��ж�ȡĳЩ����, Ϊ�ļ���ʱ������
	******************************************/
	{
		throw exception("�ļ�������");
	}
	//delete t;
	return 0;
}

int main(void) {

	memory_leak_demo1();

	/*try {
		memory_leak_Demo2();
	}
	catch (exception e) {
		cout << "catch execption: " << e.what() << endl;
	}*/

	system("pause");
	return 0;
}