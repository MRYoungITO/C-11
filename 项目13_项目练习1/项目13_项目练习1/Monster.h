#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class SpriteStone;

// ������
class Monster
{
public:
	Monster(int level = 1, const string& category = "δ֪");
	SpriteStone getValue() const;
	int getPower() const;  // ��ȡ�����޵�ս����
	friend ostream& operator<<(ostream& os, const Monster& monster);
	friend bool operator==(const Monster& one, const Monster& other);

private:
	string category;  //���޵�����
	int level;  //1-9��
};

ostream& operator<<(ostream& os, const Monster& monster);
bool operator==(const Monster& one, const Monster& other);