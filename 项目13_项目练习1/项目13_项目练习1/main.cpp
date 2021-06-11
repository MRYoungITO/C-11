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

	Monster monster2(1, "֩��");
	rock.fight(monster2);
	Monster monster3(1, "�ڻ�");
	rock.fight(monster3);
	cout << "����" << monster2 << "��" << monster3 << "֮��:" << endl;
	cout << rock << endl;

	rock.trade(monster2);
	cout << "����" << monster2 << "֮��" << endl;
	cout << rock << endl;

	rock.trade();
	cout << "������������֮��" << endl;
	cout << rock << endl;

	Immortal hanli("����", "�Ʒ��", ImmortalLevel::JIE_DAN);
	cout << hanli << endl;

	Monster monster4(2, "����");
	hanli.fight(monster4);
	cout << hanli << endl;

	rock.trade(hanli, monster4);
	cout << "ó��֮��" << endl;
	cout << rock << endl;
	cout << hanli << endl;

	Monster monster5(1, "���");
	hanli.fight(monster5);
	cout << "����" << "����" << monster5 << endl;
	cout << hanli << endl;

	cout << "Rockʹ��" << monster4 << "�ͺ�������" << monster5 << endl;
	rock.trade(monster4, hanli, monster5);
	cout << rock << endl;
	cout << hanli << endl;

	hanli.trade(monster4, rock);
	cout << "������" << monster4 << "��Rock" << endl;
	cout << rock << endl;
	cout << hanli << endl;
}

int main(void) {
	testSpriteStone();
	testMonster();
	testIImmortal();

	system("pause");
	return 0;
}