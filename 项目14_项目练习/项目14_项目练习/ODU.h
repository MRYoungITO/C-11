#pragma once
#include <string>

using namespace std;

#define ODU_TYPE_331_FLAG "331"
#define ODU_TYPE_335_FLAG "335"

enum class ODU_TYPE
{
	OUD_TYPE_331,
	ODU_TYPE_335,
	ODU_TYPE_UNKNOWN
};

// ODU��, ���ڴ������ͺ�ODU331�豸
class ODU
{
public:
	ODU();
	virtual int getTxFre();  //��ȡ����Ƶ��
	virtual bool setTxFre(int);  //���÷���Ƶ��

	virtual int getRxFre();  //��ȡ����Ƶ��
	virtual bool setRxFre(int);  //���ý���Ƶ��

	virtual float getTxPower();  //��ȡ���书��
	virtual bool setTxPower(float);  //���÷��书��

	virtual float getRxL();  //��ȡ���յ�ƽ

	virtual bool heartBeat();  //������

	virtual string name();  //��ȡ���豸������

	ODU_TYPE getODUType();  // ��ȡ��ǰODU����
protected:
	int txFre;  //����Ƶ��
	int rxFre;	//����Ƶ��
	float txPower;  //���书��
	float rxL;	//���յ�ƽ

	ODU_TYPE type;
};

