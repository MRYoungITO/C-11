#include "Computer.h"
#include <iostream>

using namespace std;

// ��ʼ���б�
Computer::Computer(const char* cpuBrand, const char* cpuVerison, int hardDisk, int memory) : cpu(cpuBrand, cpuVerison) {	//���ö�Ӧ�Ĺ��캯��
	this->hardDisk = hardDisk;
	this->memory = memory;
	//this->cpu = Cpu(cpuBrand, cpuVerison);
	cout << __FUNCTION__ << endl;
}

Computer::~Computer() {
	cout << __FUNCTION__ << endl;
}

void Computer::addVoiceBox(VoiceBox* box) {
	this->box = box;
}