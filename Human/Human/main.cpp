#include <iostream>
#include <Windows.h>
#include "Human.h"

int main(void) {
	Human h1("Young", 28, 28000), h4;
	Human h2 = h1;
	Human h3(h1);
	h4 = h1;
	h1.descripiton();
	h2.descripiton();
	h3.descripiton();
	h4.descripiton();

	cout << "-----------------------------------------" << endl;

	h1.setAddr("����");
	h2.setAddr("�ձ�");
	h3.setAddr("�¼���");
	h1.descripiton();
	h2.descripiton();
	h3.descripiton();
	h4.descripiton();

	Human h5("Young", 28, 28000);
	Human h6("LaoYang", 30, 30000);
	
	h5.compare(h6).descripiton();
	
	Human* p = &h1;
	p->compare2(&h2)->descripiton();

	cout << "������: " << h1.getHumanCount() << endl;

	system("pause");
	return 0;
}
