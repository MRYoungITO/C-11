#include <sstream>
#include "Engine.h"


Engine::Engine()
{

}

Engine::Engine(const string& brand, float verison)
{
	this->brand = brand;
	this->verison = verison;
}

Engine::~Engine()
{

}

string Engine::description() const
{
	stringstream ret;
	ret << "Ʒ��: " << brand << " �ͺ�: " << verison << endl;
	return ret.str();
}
