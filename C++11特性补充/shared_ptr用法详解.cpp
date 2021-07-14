#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <memory>
#include <vector>

using namespace std;

class Person {
public:
	Person(int v) {
		no = v;
		cout << "Construct" << no << endl;
	}
	~Person() {
		cout << "Destruct" << no << endl;
	}
	int no;
};

int main(void) {

	shared_ptr<Person> sp1;  //�յ�shared_ptr, ����ָ������ΪT�Ķ���
	shared_ptr<Person> sp2(new Person(2));  //����shared_ptr,ͬʱָ������ΪT�Ķ���

	cout << "sp2 ref_counter: " << sp2.use_count();  //��ǰ�ܿ�Person(2) �Ĺ���ָ�������

	system("pause");
	return 0;
}