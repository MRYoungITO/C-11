#pragma once
#include <string>
#include "ComputerService.h"

using namespace std;

class Computer
{
public:
	Computer();
	string description();

	// ���ⲿ��ȫ�ֺ���upgrade, ����Ϊ��������Ԫ����
	//friend void upgrade(Computer* computer);
	//friend void ComputerService::upgrade(Computer* computer);

	friend class ComputerService;
private:
	string cpu;  // �������CPUоƬ
};

