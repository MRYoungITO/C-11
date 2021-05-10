#include "Car.h"

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

}

Engine Car::getEngine() const
{
	return engine;
}

Tire* Car::getTires(int i)
{
	return &tires[i];
}
