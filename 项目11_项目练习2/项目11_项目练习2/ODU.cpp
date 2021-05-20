#include <sstream>
#include "ODU.h"

ODU::ODU()
{

}

ODU::~ODU()
{

}

float ODU::getTxPower() const
{
	return txPower;
}

int ODU::getTxFreq() const
{
	return txFreq;
}

float ODU::getBandwidth() const
{
	return bandWidth;
}

bool ODU::setTxPower(float power)
{
	// ��Ʒʵ����Ŀ��, ��ͨ�����ڷ��Ϳ��ư�ʵ�ֵġ�
	txPower = power;
	return true;
}

bool ODU::setTxFreq(int frequency)
{
	txFreq = frequency;
	return true;
}

bool ODU::setBandwidth(float bandWidth)
{
	this->bandWidth = bandWidth;
	return true;
}

string ODU::description() {
	stringstream ret;
	ret << "���书��: " << txPower << "\t����Ƶ��: " << txFreq
		<< "\t����: " << bandWidth;
	return ret.str();
}
