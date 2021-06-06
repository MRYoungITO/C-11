#include "Monster.h"
#include "SpriteStone.h"

Monster::Monster(int level, const string& category)
{
	this->level = level;
	this->category = category;
}

/*
1�����ޣ���ֵ 100��   ������ʯ
2�����ޣ���ֵ 200��   ������ʯ
3�����ޣ���ֵ 500��   ������ʯ
4�����ޣ���ֵ 1000     ������ʯ
5�����ޣ���ֵ 2000     ������ʯ
6�����ޣ���ֵ 5000     ������ʯ
7�����ޣ���ֵ 10000   ������ʯ
8�����ޣ���ֵ 20000   ������ʯ
9�����ޣ���ֵ 100000 ������ʯ
*/
SpriteStone Monster::getValue()
{
	int stoneCount[] = { 100,200,500,1000,2000,5000,10000,20000,100000 };
	int count = stoneCount[level - 1];
	return SpriteStone(count, SpriteStoneLevel::PRIMARY_LEVEL);
}

ostream& operator<<(ostream& os, const Monster& monster)
{
	os << monster.level << "��" << monster.category << "����";
	return os;
}
	
