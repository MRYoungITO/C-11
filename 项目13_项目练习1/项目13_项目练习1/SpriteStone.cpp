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

SpriteStone SpriteStone::operator+(const SpriteStone& stone)
{
	int sum = 0;
	if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum += stone.count;
	}
	else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum += stone.count * 10;
	}
	else if (stone.level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum += stone.count * 100;
	}

	if (this->level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum += this->count;
	}
	else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum += this->count * 10;
	}
	else if (this->level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum += this->count * 100;
	}

	return SpriteStone(sum, SpriteStoneLevel::PRIMARY_LEVEL);
}

SpriteStone SpriteStone::operator-(const SpriteStone& stone)
{
	int sum1 = 0;
	if (this->level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum1 = this->count;
	}
	else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum1 = this->count * 10;
	}
	else if (this->level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum1 = this->count * 100;
	}

	int sum2 = 0;
	if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum2 = stone.count;
	}
	else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum2 = stone.count * 10;
	}
	else if (stone.level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum2 = stone.count * 100;
	}

	return SpriteStone(sum1 - sum2, SpriteStoneLevel::PRIMARY_LEVEL);
}

int SpriteStone::getCount()
{
	return this->count;
}

bool SpriteStone::operator>=(const SpriteStone& stone)
{
	int sum1 = 0;
	if (this->level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum1 = this->count;
	}
	else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum1 = this->count * 10;
	}
	else if (this->level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum1 = this->count * 100;
	}

	int sum2 = 0;
	if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum2 = stone.count;
	}
	else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum2 = stone.count * 10;
	}
	else if (stone.level == SpriteStoneLevel::ADVANCE_LEVEL) {
		sum2 = stone.count * 100;
	}

	/*if (sum1 >= sum2) {
		return true;
	}
	else {
		return false;
	}*/
	return sum1 >= sum2;
}

ostream& operator<<(ostream& os, SpriteStone& stone)
{
	os << stone.str();
	return os;
}
