#include "Human.h"
#include <sstream>


Human::Human() {

}

Human::Human(const string& name, gender_t gender, int age) {
	this->name = name;
	this->gender = gender;
	this->age = age;
}

Human::~Human() {

}

string Human::getName() const {
	return name;
}

int Human::getAge() const {
	return age;
}

gender_t Human::getGender() const {
	return gender;
}

Human* Human::getLover() const
{
	return lover;
}

vector<Human*> Human::getFriends() const {
	return friends;
}

string Human::description() const {
	stringstream des;
	des << name << "-age: " << age << "-" << (gender == MAN ? "��" : "Ů");
	return des.str();
}

void Human::marry(Human& other) {
	if (gender == other.gender) {
		return;
	}
	this->lover = &other;
	other.lover = this;
}

void Human::divorce() {
	if (this->lover == NULL) {
		return;
	}
	lover->lover = NULL;
	lover = NULL;
}

void Human::addFriend(Human& other) {  // & ���������� 
	friends.push_back(&other);  // & ������ȡ��ַ��
}

void Human::delFriend(Human& other) {
	//auto x = 100;  //int x = 100;  �Զ��Ƶ������÷�
	//auto y = 3.14;	//double y = 3.14;
	//friends.begin() ����һ�������ָ��, ָ���һ����Ա! ! ! > "������"
	//���� &friends[0]
	// friends.end() ����һ��������, ָ�����һ��Ԫ�ص���һ��λ��
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &other) {
			it = friends.erase(it);  //erase����, ����ֵ��Ҳ��һ��������, ָ����һ����Ա
		}
		else {
			it++;
		}
	}
}
