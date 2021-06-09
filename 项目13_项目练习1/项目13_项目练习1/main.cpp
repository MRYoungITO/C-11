#include <iostream>
#include <Windows.h>
#include <string>
#include "SpriteStone.h"
#include "Monster.h"
#include "Immortal.h"

void testSpriteStone() {
	SpriteStone stone(100, SpriteStoneLevel::MIDDLE_LEVEL);
	cout << stone << endl;
}

void testMonster() {
	Monster monster(5, "����");
	monster.getValue();
	cout << monster << endl;
}

void testIImmortal() {
	Immortal rock("Rock", "��ţ", ImmortalLevel::LIAN_QI);
	cout << rock << endl;

	for (int i = 0; i < 50; i++) {
		rock.mining();
	}

	cout << rock << endl;

	Monster monster(1, "����");
	rock.fight(monster);
	cout << "����" << monster << "֮��:" << endl;
	cout << rock << endl;
}

int main(void) {
	testSpriteStone();
	testMonster();
	testIImmortal();

	system("pause");
	return 0;
}