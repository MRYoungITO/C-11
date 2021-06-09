#pragma once
#include <string>
#include <vector>
#include <iostream>

class SpriteStone;
class Monster;

using namespace std;


//���������ڣ� ������, �ᵤ�ڣ�ԪӤ�ڣ� �����ڣ�
//			�����ڣ������ڣ�����ڣ��ɽ��ڣ�

enum class ImmortalLevel {
	LIAN_QI,
	ZHU_JI,
	JIE_DAN,
	YUAN_YING,
	HUA_SHEN,
	LIAN_XU,
	HE_TI,
	DA_CHENG,
	DU_JIE
};

// ��������
class Immortal
{
public:
	Immortal(const char* name, const char* menPai, ImmortalLevel level);

	// �ڿ�
	void mining();

	// ���г��������е�����
	bool trade();
	// ���г�����ָ��������
	bool trade(const Monster& monster);
	// ���Լ�����ʯ, ���������������ߵ�ָ������
	bool trade(Immortal& other, const Monster& monster);
	// ���Լ�ָ��������, �������������ߵ�ָ�������޽��жԻ�
	bool trade(const Monster& monsterSource, Immortal& other, const Monster& monsterDest);
	// ���Լ�������, ������������������, �Ի�ȡ��ʯ
	bool trade(const Monster& monster, Immortal& other);

	int getPower() const;
	// ��������
	void fight(const Monster& monster);

	friend ostream& operator<<(ostream& os, const Immortal& immortal);
	friend ostream& operator<<(ostream& os, const ImmortalLevel& level);

	void dead();  // ������������Ĵ���
private:
	string name;
	string menPai;  // ����
	ImmortalLevel level;  // �����ߵļ���
	vector<SpriteStone> stones; //��ʯ�ʲ�
	vector<Monster> monsters; // �����ʲ�
	bool alive;  // ����״̬

	bool hadMonster(const Monster& monster);  // �ж��Ƿ���ָ��������
	bool removeMonster(const Monster& monster); // �Ƴ�ָ��������
};

ostream& operator<<(ostream& os, const Immortal& immortal);
ostream& operator<<(ostream& os, const ImmortalLevel& level);
