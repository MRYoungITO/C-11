#include <Windows.h>
#include "Son.h"

int main(void) {
	Son wsc("��", "˼��", "����", "�羺");

	wsc.playBasketball();

	// ������ؼ̳еĶ����Եķ���1:
	// ʹ�� "����::" ����ָ��, ָ�����ô��Ǹ�����̳еķ��� !
	wsc.Father::dance();
	wsc.Mother::dance();

	// ������ؼ̳еĶ����Եķ���2:
	// ������������ʵ�����ͬ������,������������ڲ�, ʹ�û����������޶�, �����ö�Ӧ�Ļ��෽��
	wsc.dance();

	wsc.playGame();

	system("pause");
	return 0;
}