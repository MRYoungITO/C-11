#pragma once
#include "Book.h"

class SellBook :public Book
{
public:
	SellBook(float price, string isbn, float discount = 10.0);
	~SellBook();

	float getDiscount();
	void setDiscount(float discount);
	float getPrice(); //��д�Լ���getPrice();

private:
	float discount; // �ۿ�
};