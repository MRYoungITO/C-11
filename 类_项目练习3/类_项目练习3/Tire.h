#pragma once
#include <string>

using namespace std;

class Tire
{
public:
	Tire(const string& brand="������");
	~Tire();

	string getBrand() const;
	float getPressure() const;
	string description() const;

private:
	string brand;  //Ʒ��
	float pressure;  //̥ѹ
};

