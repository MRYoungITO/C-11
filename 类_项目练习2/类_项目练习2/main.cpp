#include <Windows.h>
#include <iostream>
#include "Human.h"

int main(void) {
	Human lhc("�����", MAN, 25);
	Human ryy("��ӯӯ", WOMEN, 26);
	Human tbg("�ﲮ��", MAN, 30);
	Human yls("����ɺ", WOMEN, 20);
	Human cx("�������", MAN, 55);

	lhc.marry(yls);
	Human* who = lhc.getLover();
	cout << lhc.getName() << "����ż��: " << who->description() << endl;
	cout << who->getName() << "����ż��: " << who->getLover()->description() << endl;

	cout << lhc.getName() << "���" << endl << endl;
	lhc.divorce();

	if (lhc.getLover() == NULL) {
		cout << lhc.getName() << "����" << endl;
	}
	else {
		cout << lhc.getName() << "���ʧ��" << endl;
	}

	lhc.addFriend(cx);
	lhc.addFriend(tbg);
	vector<Human*> friends = lhc.getFriends();
	for (int i = 0; i < friends.size(); i++) {
		cout << friends[i]->description() << endl;
	}

	lhc.delFriend(tbg);
	cout << lhc.getName() << "ɾ������: " << tbg.getName() << endl;
	friends = lhc.getFriends();
	for (int i = 0; i < friends.size(); i++) {
		cout << friends[i]->description() << endl;
	}

	system("pause");
	return 0;
}