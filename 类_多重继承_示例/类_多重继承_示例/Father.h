#pragma once
#include <string>
using namespace std;
class Father
{
public:
	Father(const char* lastName="����",const char* firstName="����");
	~Father();

	void playBasketball() const;  //������
protected:
	string lastName;  //��
	string firstName;  //����
};

