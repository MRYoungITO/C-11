#pragma once
#include <vector>
#include "Boy.h"
#include "Girl.h"

using namespace std;

/*
* ���ܣ�
*	init() //��ʼ���� ���ļ��ж�ȡ������Ϣ�� ����ʼ���û�����
*	autoPair() //�Զ����
*	print()  // ��ӡ�����ݿ��е������û���Ϣ
* ���ݣ�
*	vector<Boy> boys;  //���еĵ�������Ϣ
*	vector<Girl> girls; //���е���Ů��Ϣ
*/

class Database
{
public:
	Database();

	// ��ʼ���� ���ļ��ж�ȡ������Ϣ�� ����ʼ���û�����
	void init();

	// �Զ����
	void autoPair();

	// ��ӡ�����ݿ��е������û���Ϣ
	void print();
private:
	// ���еĵ�������Ϣ
	vector<Boy> boys;

	//���е���Ů��Ϣ
	vector<Girl> girls;

	// ���ļ��е���Ϣ����ʼ��boys
	void initBoysFromFile();

	// ���ļ��е���Ϣ����ʼ��girls
	void initGirlsFromFile();

	// ����boys����Ϣ���ļ���
	void saveBoys();

	// ����girl s����Ϣ���ļ���
	void saveGirls();
};


