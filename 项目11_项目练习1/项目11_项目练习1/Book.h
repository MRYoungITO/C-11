#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book(float price, string isbn);
	~Book();

	float getPrice();  //�鿴�۸�
	string getISBN();  //�鿴���

protected:
	float price;
	string ISBN; //���
};