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

class DestructPerson {
public:
	void operator()(Person* pt) {
		cout << "Destruction..." << endl;
		delete pt;
	}
};

int main(void) {

	shared_ptr<Person> sp1;  //�յ�shared_ptr, ����ָ������ΪT�Ķ���
	shared_ptr<Person> sp2(new Person(2));  //����shared_ptr,ͬʱָ������ΪT�Ķ���

	cout << "sp1 ref_counter: " << sp1.use_count() << endl;  //��ǰ�ܿ�Person(2) �Ĺ���ָ�������
	cout << "sp2 ref_counter: " << sp2.use_count() << endl;

	sp1 = sp2;
	cout << "after sp1 = sp2, sp2 ref_counter: " << sp2.use_count() << endl;

	shared_ptr<Person> sp3(sp1);
	cout << "after sp3(sp1), sp3 ref_counter: " << sp3.use_count() << endl;

	//�������Ĺ���
	shared_ptr<Person[]> sp4(new Person[5]{ 3,4,5,6,7 });  //delete[]
	cout << "sp4 ref_counter: " << sp4.use_count() << endl;

	shared_ptr<Person> sp8(new Person(8), DestructPerson()); //���� DesrtuctPerson() �ͷŶ���

	//ʹ��make_shared ����ģ���ʼ��
	shared_ptr<Person> sp9;
	sp9 = make_shared<Person>(9);
	cout << "after sp9 = make_shared<Person>(9), sp ref_counter: " << sp9.use_count() << endl;

	shared_ptr<Person> sp10 = sp9;
	Person* p10 = new Person(10);
	sp9.reset(p10);
	cout << "after sp9.reset(p10), sp ref_counter: " << sp9.use_count() << endl;
	
	//����swap ����
	std::swap(sp9, sp10);

	cout << "������, sp9: " << sp9->no << " sp10: " << sp10->no << endl;
	sp9.swap(sp10);
	cout << "������, sp9: " << sp9->no << " sp10: " << sp10->no << endl;

	system("pause");
	return 0;
}