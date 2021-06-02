#pragma once
#include <string>
#include <iostream>

#define AGE_KEY "age"
#define SALARY_KEY "salary"
#define DARK_HORSE_KEY "darkHorse"
#define POWER_KEY "power"

// ö�����ͱ�ʾ
typedef enum {
	AGE,
	SALARY,
	DARK_HORSE,
	POWER
}BOY_KEY_TYPE;

using namespace std;

class Boy
{
public:
	Boy(const char* name, int age, int salary,
		int darkHorse);
	~Boy();

	Boy(int salary);
	Boy(const char* name);

	string description();

	

	// ���ظ�ֵ�����
	Boy& operator=(const Boy& boy);  //�������������� & ����, �����м�const����ʵ�ʲ������ᱻ�޸�

	bool operator>(const Boy& boy);
	bool operator<(const Boy& boy);
	bool operator==(const Boy& boy);

	// �������������, ����Ҫ��������
	operator int() const;
	operator char* () const;

	// ʵ���±������������
	int operator[](string index) const;
	int operator[](int index) const;

	//ostream& operator<<(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Boy& boy);
	friend istream& operator>>(istream& is, Boy& boy);

private:
	char* name;
	int age;
	int salary;
	int darkHouse;  // ����ֵ, ��ʾǱ��ϵ��
	unsigned int id;  //���
	static int LAST_ID;

	int power() const;  // �ۺ�����ֵ
};

ostream& operator<<(ostream& os, const Boy& boy);
istream& operator>>(istream& is, Boy& boy);