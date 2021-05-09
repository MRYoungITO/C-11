#pragma once
#include <string>
#include <vector>

using namespace std;

typedef enum gender {
	MAN,  //��
	WOMEN  //Ů
} gender_t;

class Human
{
public:
	Human();
	Human(const string& name, gender_t gender, int age);
	~Human();

	string getName() const;
	int getAge() const;
	gender_t getGender() const;
	Human* getLover() const;
	vector<Human*> getFriends() const;
	string description() const;

	void marry(Human& other);
	void divorce();  //���
	void addFriend(Human& other);
	void delFriend(Human& other);

private:
	string name;  //�ǳ�
	int age;
	gender_t gender;  //�Ա�
	Human* lover = NULL;  //��ż, ����(�ۺ�˼��)
	vector<Human*> friends;
};

