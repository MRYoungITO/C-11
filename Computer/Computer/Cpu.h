#pragma once

#include <string>

class Cpu
{
public:
	Cpu(const char* brand = "Inter", const char* verison = "i5");
	~Cpu();

private:
	std::string brand;		//Ʒ��
	std::string verison;	//�ͺ�
};