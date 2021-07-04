#include <set>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

class student {
public:
	student(int age) {
		this->age = age;
	}

	bool operator<(const student& right) const{
		return this->age < right.age;
	}

	bool operator>(const student& right) const {
		return this->age > right.age;
	}

	int getAge() const {
		return age;
	}

private:
	int age;
	string name;
};

class FunStudent {
public:
	bool operator()(const student& left, const student& right) const {
		cout << "������ FunStudent ." << endl;
		return left < right;
	}
public:
	int ret;
};

int main(void) {

	//less ��������ʵ�ֱȽ�, Ϊ�����ṩ����
	//less �� greater ���Ǻ�������, �ֽзº���
	//set<int, less<int>> set1;

	set<int, greater<int>> set1;

	for (int i = 5; i > 0; i--) {
		set1.insert(i);
	}

	//less<student>
	set<student, FunStudent> setStu;  //��ͬ�� set<student, less<student>>
	student lixiaohua(18);
	student wangdachui(19);
	
	//��������(�º���)��������һ��ֱ�ӵ���
	FunStudent funStu;
	bool ret = funStu(lixiaohua, wangdachui);

	cout << "�ȽϽ��: " << ret << endl;

	setStu.insert(lixiaohua);
	setStu.insert(wangdachui);

	/*for (set<int, greater<int>>::iterator it = set1.begin(); it != set1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;*/

	for (set<student, FunStudent>::iterator it = setStu.begin(); it != setStu.end(); it++) {
		cout << it->getAge() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}