#include <iostream>
#include <string>
#include <sstream>
#include "ODU.h"

ODU::ODU()
{
	txFre = 34400;
	rxFre = 31100;
	txPower = 20;
	rxL = 0;
	type = ODU_TYPE::OUD_TYPE_331;

	cout << "����ODU()" << endl;
}

int ODU::getTxFre()
{
	return txFre;
}

bool ODU::setTxFre(int frequence)
{
	txFre = frequence;
	cout << name() << "����Ƶ���Ѿ�����Ϊ" << txFre << "Hz" << endl;
	return true;
}

int ODU::getRxFre()
{
	return rxFre;
}

bool ODU::setRxFre(int frequence)
{
	rxFre = frequence;
	cout << name() << "����Ƶ���Ѿ�����Ϊ" << rxFre << "Hz" << endl;
	return true;
}

float ODU::getTxPower()
{
	return txPower;
}

bool ODU::setTxPower(float power)
{
	txPower = power;
	cout << name() << "���书���Ѿ�����Ϊ" << txPower << "dBm" << endl;
	return true;
}

float ODU::getRxL()
{
	return rxL;
}

bool ODU::heartBeat()
{
	cout << name() << "ģ�⴮��Э���ȡ����: ��ȡ�������ķ���. . .��"
		<< ODU_TYPE_331_FLAG << "��";
	string response;
	cin >> response;
	bool ret = false;

	if (response == ODU_TYPE_331_FLAG) {
		type = ODU_TYPE::OUD_TYPE_331;
		ret = true;
	}

	return ret;
}

string ODU::name()
{
	string ret;
	switch (type) {
	case ODU_TYPE::OUD_TYPE_331:
		ret = "ODU331";
		break;
	case ODU_TYPE::ODU_TYPE_335:
		ret = "ODU335";
		break;
	case ODU_TYPE::ODU_TYPE_UNKNOWN:
	default:
		ret = "ODU_UNKNOWN";
		break;
	}
	return ret;
}

ODU_TYPE ODU::getODUType()
{
	return type;
}
