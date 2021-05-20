#pragma once
#include <string>
using namespace std;
class ODU
{
public:
	ODU();
	~ODU();

	float getTxPower() const;
	int getTxFreq() const;
	float getBandwidth() const;

	bool setTxPower(float power);
	bool setTxFreq(int frequency);
	bool setBandwidth(float bandWidth);

	string description();

protected:
	float txPower;  //���书��
	int txFreq;  //����Ƶ��
	float bandWidth;  //����, ��λ: M
};


