#include <iostream>
#include <Windows.h>
#include <thread>  // �߳� ͷ�ļ�
#include "ODU.h"
#include "ODU335.h"

using namespace std;

ODU* odu = NULL;  // odu ȫ�ֱ���

void test(ODU* odu) {
	odu->setTxFre(35588);
	cout << odu->getTxFre() << endl;
	odu->heartBeat();
}

void oduMonitorHandler() {
	while (1) {
		if (!odu->heartBeat()) {
			// �л�ODU
			ODU_TYPE type = odu->getODUType();
			switch (type) {
			case ODU_TYPE::OUD_TYPE_331:
				delete odu;
				odu = new ODU335;
				break;
			case ODU_TYPE::ODU_TYPE_335:
				delete odu;
				odu = new ODU;
				break;
			default:
				odu = NULL;
				return;
			}
		}

		Sleep(3000);
	}
}

int main(void) {
	odu = new ODU;

	//  ����һ���߳�, ���ڶ�ODU�����������
	thread oduMonitor(oduMonitorHandler);

	// ���̵߳ȴ��߳�oduMonitor�Ľ���
	oduMonitor.join();

	system("pause");
	return 0;
}