#include <Windows.h>
#include <iostream>
#include "Toy.h"

int main(void) {
	Toy toy("���ν��", 5600, "China");
	cout << toy.getName() << " : " << toy.getPrice() << " : " << toy.getOrigin() << endl;
	
	cout << "�޸��ۿۺ�" << endl;
	toy.setDiscount(0.5);
	cout << toy.getName() << " : " << toy.getPrice() << " : " << toy.getOrigin() << endl;

	system("pause");
	return 0;
}