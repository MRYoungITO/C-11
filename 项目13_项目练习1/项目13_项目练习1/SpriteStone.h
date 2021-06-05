#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class SpriteStoneLevel {
	PRIMARY_LEVEL,
	MIDDLE_LEVEL,
	ADVANCE_LEVEL,
	SPRITE_STONE_LEVEL_COUNT
};

// ��ʯ��
class SpriteStone
{
public:
	SpriteStone(int count = 0, SpriteStoneLevel level = SpriteStoneLevel::PRIMARY_LEVEL);
	string str() const;
	friend ostream& operator<<(ostream& os, const SpriteStone& stone);
private:
	int count;  // ��ʯ������: xxx��
	SpriteStoneLevel level;  // ��ʯ�ĵȼ�
};

ostream& operator<<(ostream& os, const SpriteStone& stone);