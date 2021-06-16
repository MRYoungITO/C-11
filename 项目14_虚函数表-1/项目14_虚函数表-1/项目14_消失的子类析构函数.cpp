#include <iostream>
#include <Windows.h>
#include <string.h>

using namespace std;

class Father {
public:
	Father(const char* addr = "�й�") {
		cout << "ִ����Father�Ĺ��캯��" << endl;
		int len = strlen(addr) + 1;
		this->addr = new char[len];
		strcpy_s(this->addr, len, addr);
	}

	// ��Father���������������Ϊvirtual����ʱ, 
	// �����Father���ָ��ʹ��delete����ʱ,
	// �ͻ�Ը�ָ��ʹ��"��̬����"
	// ������ָ��ָ������������,
	// name���ȵ��ø��������������,�ٵ����Լ������������
	virtual ~Father() {
		cout << "ִ����Father����������" << endl;
		if (addr) {
			delete addr;
			addr = NULL;
		}
	}
private:
	char* addr;
};

class Son : public Father {
public:
	Son(const char* game="�Լ�", const char*addr="�й�") : Father(addr) {
		cout << "ִ����Son�Ĺ��캯��" << endl;
		int len = strlen(game) + 1;
		this->game = new char[len];
		strcpy_s(this->game, len, game);
	}
	~Son() {
		cout << "ִ����Son����������" << endl;
		if (game) {
			delete game;
			game = NULL;
		}
	}
private:
	char* game;
};

int main(void) {
	cout << "----- case 1 -----" << endl;
	Father* father = new Father();
	delete father;

	cout << "----- case 2 -----" << endl;
	Son* son = new Son();
	delete son;

	cout << "----- case 3 -----" << endl;
	father = new Son();
	delete father;

	system("pause");
	return 0;
}