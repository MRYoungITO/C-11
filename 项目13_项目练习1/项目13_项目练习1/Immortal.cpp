#include "Immortal.h"
#include "SpriteStone.h"
#include "Monster.h"

#define IMMORTAL_LEVEL_FACTOR 1000
#define SPRITE_FACTOR 0.1
#define MONSTER_FACTOR 0.1

Immortal::Immortal(const char* name, const char* menPai, ImmortalLevel level)
{
	this->name = name;
	this->menPai = menPai;
	this->level = level;
	this->alive = true;
}

void Immortal::mining()
{
	stones.push_back(SpriteStone(100, SpriteStoneLevel::PRIMARY_LEVEL));
}

bool Immortal::trade()
{
	if (!alive) {
		return false;
	}
	SpriteStone stone;
	for (int i = 0; i < monsters.size(); i++) {
		// ����ʹ��+=, ��Ϊֻ������+
		stone = stone + monsters[i].getValue();
	}
	stones.push_back(stone);
	monsters.erase(monsters.begin(), monsters.end());

	return true;
}

bool Immortal::trade(const Monster& monster)
{
	if (!alive) {
		return false;
	}

	// �ж��Ƿ������ָ��������
	if (!hadMonster(monster)) {
		cout << name << "û��" << monster << endl;
		return false;
	}

	SpriteStone stone = monster.getValue();
	stones.push_back(stone);
	removeMonster(monster);
}

bool Immortal::trade(Immortal& other, const Monster& monster)
{
	return false;
}

bool Immortal::trade(const Monster& monsterSource, Immortal& other, const Monster& monsterDest)
{
	return false;
}

bool Immortal::trade(const Monster& monster, Immortal& other)
{
	return false;
}

int Immortal::getPower() const
{
	// ���������߼����ս����
	int ret = ((int)level + 1) * IMMORTAL_LEVEL_FACTOR;

	// ������ʯ����ս����
	SpriteStone stone;
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}
	ret += stone.getCount() * SPRITE_FACTOR;

	// �����������޵�����ս����
	for (int i = 0; i < monsters.size(); i++) {
		ret += monsters[i].getPower() * MONSTER_FACTOR;
	}

	return ret;
}

void Immortal::fight(const Monster& monster)
{
	int selfPower = getPower();
	int monsterPower = monster.getPower();
	if (selfPower > monsterPower) {
		monsters.push_back(monster);
	}
	else if (selfPower < monsterPower) {
		dead();
	}
}

void Immortal::dead()
{
	this->alive = false;
	stones.erase(stones.begin(), stones.end());
	monsters.erase(monsters.begin(), monsters.end());
}

bool Immortal::hadMonster(const Monster& monster)
{
	for (int i = 0; i < monsters.size(); i++) {
		if (monster == monsters[i]) {
			return true;
		}
	}
	return false;
}

bool Immortal::removeMonster(const Monster& monster)
{
	// ��һ��������, ��һ�������ָ��, ָ��Monsters�еĵ�һ����Ա��λ��
	vector<Monster>::iterator it = monsters.begin();
	while (it != monsters.end()) {
		if (*it == monster) {
			it = monsters.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

ostream& operator<<(ostream& os, const Immortal& immortal)
{
	os << "[������]" << immortal.name
		<< (immortal.alive ? "[����]" : "[����]")
		<< "\t����:" << immortal.menPai
		<< "\t����:" << immortal.level;  // ����

	SpriteStone stone;
	for (int i = 0; i < immortal.stones.size(); i++) {
		stone = stone + immortal.stones[i];
	}
	os << "\t��ʯ: �ۺ�" << stone;
	os << "\t����:";
	if (immortal.monsters.size() == 0) {
		os << "��";
	}
	else {
		for (int i = 0; i < immortal.monsters.size(); i++) {
			os << immortal.monsters[i] << " ";
		}
	}
	return os;
}

// ���������ڣ�������,  �ᵤ�ڣ�ԪӤ�ڣ� �����ڣ������ڣ������ڣ�����ڣ��ɽ��ڣ�
ostream& operator<<(ostream& os, const ImmortalLevel& level)
{
	switch (level) {
	case ImmortalLevel::LIAN_QI:
		os << "������";
		break;
	case ImmortalLevel::ZHU_JI:
		os << "������";
		break;
	case ImmortalLevel::JIE_DAN:
		os << "�ᵤ��";
		break;
	case ImmortalLevel::YUAN_YING:
		os << "ԪӤ��";
		break;
	case ImmortalLevel::HUA_SHEN:
		os << "������";
		break;
	case ImmortalLevel::LIAN_XU:
		os << "������";
		break;
	case ImmortalLevel::HE_TI:
		os << "������";
		break;
	case ImmortalLevel::DA_CHENG:
		os << "�����";
		break;
	case ImmortalLevel::DU_JIE:
		os << "�ɽ���";
		break;
	}

	return os;
}
