#include <Windows.h>
#include <iostream>
#include "Father.h"
#include "Son.h"

int main(void) {
	Father wjl("������", 68);
	Son wsc("��˼��", 32, "�羺");

	cout << wjl.description() << endl;
	cout << wsc.description() << endl;

	system("pause");
	return 0;
}