#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	int rows = 0;
	
	cout << "������������";
	cin >> rows;

	for (int i=0; i<rows; i++) {
		for (int j=0; j<i+1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}