#include "SpriteStone.h"
#include <sstream>

SpriteStone::SpriteStone(int count, SpriteStoneLevel level)
{
	this->count = count;
	this->level = level;
}

string SpriteStone::str() const
{
	stringstream ret;
	ret << count << "��";

	switch (level) {
	case SpriteStoneLevel::PRIMARY_LEVEL:
		ret << "������ʯ";
		break;
	case SpriteStoneLevel::MIDDLE_LEVEL:
		ret << "�м���ʯ";
		break;
	case SpriteStoneLevel::ADVANCE_LEVEL:
		ret << "�߼���ʯ";
		break;
	default:
		ret << "δ֪��ʯ";
		break;
	}
	return ret.str();
}

ostream& operator<<(ostream& os, SpriteStone& stone)
{
	os << stone.str();
	return os;
}
