#include <sstream>
#include "SpriteStone.h"

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
	case SpriteStoneLevel::MIDDLE_LEVEL:
		ret << "�н���ʯ";

	}
}
