#include <sstream>
#include <iostream>
#include "Car.h"

using namespace std;

Car::Car(const string& carBrand, const string& carVeriosn, int carPrice, 
	const string& engineBrand, float engineVer, 
	const string& tireBrand) 
	: engine(engineBrand, engineVer),   // (���а���������ʱ) ��ʼ���б�
	tires{tireBrand, tireBrand, tireBrand, tireBrand}  // (���а���������ʱ) ��ʼ���б�(�����Դ�������ʽ��ʾ)
{
	this->brand = carBrand;
	this->verison = carVeriosn;
	this->price = carPrice;
	this->miles = 0;
}

Car::~Car()
{
	cout << __FUNCTION__ << endl;
}

Engine Car::getEngine() const
{
	return engine;
}

const Tire* Car::getTires(int i) const
{
	if (i >= 1 && i <= 4) {
		return &tires[i];
	}
	else {
		return NULL;
	}
}

string Car::getBrand() const
{
	return brand;
}

string Car::getVerison() const
{
	return verison;
}

int Car::getPrice() const
{
	return price;
}

int Car::getMiles() const
{
	return miles;
}

string Car::description() const
{
	stringstream ret;
	ret << "����Ʒ��: " << brand << "-" << verison << "-$ " << price
		<< "\t\t����" << engine.description()
		<< "\t\t��̥" << tires[0].description();
	return ret.str();
}
