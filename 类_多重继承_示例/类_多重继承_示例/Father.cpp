#include <iostream>
#include "Father.h"

Father::Father(const char* lastName, const char* firstName)
{
	cout << __FUNCTION__ << endl;
	this->lastName = lastName;
	this->firstName = firstName;
}

Father::~Father()
{

}

void Father::playBasketball() const
{
	cout << "����, ��Ҫ����������!" << endl;
}

void Father::dance() const
{
	cout << "һ����locking���, һ������, ��������..." << endl;
}
