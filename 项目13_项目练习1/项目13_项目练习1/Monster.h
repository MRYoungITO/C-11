#pragma once
#include <string>
#include <iostream>

using namespace std;

class SpriteStone;

// ������
class Monster
{
public:
	Monster(int level = 1, const string& category = "δ֪");
	SpriteStone getValue();
	friend ostream& operator<<(ostream& os, const Monster& monster);
private:
	string category;  //���޵�����
	int level;  //1-9��
};

ostream& operator<<(ostream& os, const Monster& monster);