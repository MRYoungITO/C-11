#pragma once
#include "Cpu.h"
//#include "VoiceBox.h"

class VoiceBox;

class Computer
{
public:
	Computer(const char* cpuBrand, const char* cpuVerison, int hardDisk, int memory);
	~Computer();
	void addVoiceBox(VoiceBox* box);

private:
	Cpu cpu;			//Computer��Cpu֮��,����"���"
	int hardDisk;		//Ӳ��, ��λ: G
	int memory;		//�ڴ�, ��λ: G
	VoiceBox* box;
};

