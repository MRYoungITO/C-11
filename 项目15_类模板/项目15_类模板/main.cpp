#include <Windows.h>
#include "��ģ�庯����ͷ�ļ��ֿ�.hpp"

int main(void) {
	A<int> a(666), b(888);

	A<int> tmp = a + b;

	tmp.print();

	system("pause");
	return 0;
}