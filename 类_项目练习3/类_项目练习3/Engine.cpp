#include <sstream>
#include <iostream>
#include "Engine.h"

using namespace std;

Engine::Engine(const string& brand, float verison)
{
	this->brand = brand;
	this->verison = verison;
}

Engine::~Engine()
{
	cout << __FUNCTION__ << endl;
}

string Engine::description() const
{
	stringstream ret;
	ret << "Ʒ��: " << brand << " �ͺ�: " << verison << endl;
	return ret.str();
}
