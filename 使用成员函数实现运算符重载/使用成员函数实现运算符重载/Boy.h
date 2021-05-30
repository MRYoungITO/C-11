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
	Boy(const char* name = NULL, int age = 0, int salary = 0, 
		int darkHorse = 0);
	~Boy();

	string description();
	
	// ���ظ�ֵ�����
	Boy& operator=(const Boy& boy);  //�������������� & ����, �����м�const����ʵ�ʲ������ᱻ�޸�

	bool operator>(const Boy& boy);
	bool operator<(const Boy& boy);
	bool operator==(const Boy& boy);

	// ʵ���±������������
	int operator[](string index);
	int operator[](int index);

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

