#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "Database.h"
#include "Boy.h"
#include "Girl.h"

/*
* ����: Ҫʹ���ļ��������û���Ϣ
* ����: ���һ������ʵ����Ϣ�ı��湦��
* Database    ���ݿ�
* ����:
*		init()  //��ʼ��, ���ļ��ж�ȡ������Ϣ, ����ʼ���û�����
*		autoPair()  //�Զ����
*		print()  //��ӡ��ǰ���ݿ��е�������Ϣ
* ����:
*		vector<Boy> boys;  //���еĵ�������Ϣ
*		vector<Girloy> Goys;  //���еĵ�������Ϣ
*/

int main(void) {
	Database data;

	data.init();

	Boy boy;
	Boy::inputBoy(boy);  // ����boy��Ϣ
	data.addOne(boy);

	Girl girl;
	Girl::inputGirl(girl);
	data.addOne(girl);
		
	system("pause");
	return 0;
}

/*
����������
25 ��� 15000
28 ���� 8000
35 ���� 50000
0
18 С��Ů 95
25 �绨 79
26 ���� 90
26 ��Ī�� 100
0
*/