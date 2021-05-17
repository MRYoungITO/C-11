#include <stdio.h>
#include <Windows.h>

void init(char* data, int len) {
	// ����ʵ��������ʵ��
	// ����ֻ��Ϊ�˲����㷨Ч��, ����:
	// �ܹ���3����������, ������������� [���������]
	// ������40�ڸ�����: 
	unsigned int n = len * 8;  //һ����n������
	for (unsigned int i = 0; i < n; i++) {
		// ����: �ܹ���3����������, ������������� [���������]
		if (i % 3 == 0) {
			// �������λ�ö�Ӧ�ĸ��ֽ�
			char* p = data + i / 8;
			*p = *p | (1 << (i % 8));
		}
	}
}

//λͼ�㷨
bool check(char* data, int len, int value) {
	// ��λ��ָ�����ֽ�
	char* p = data + value / 8;

	// �ж�����ֽ���ָ����λ�Ƿ�Ϊ1
	bool ret = *p & (1 << (value % 8));
	return ret;
}

int main(void) {
	// ����һ���㹻���ڴ�, ������ʾλͼ
	unsigned int n = 4000000000;
	int len = n / 8 + 1;
	char* data = (char*)malloc(len);
	memset(data, 0, len);  //����

	//װ�����ݼ���(ֻ��Ҫװ��һ��)
	init(data, len);

	while (1) {
		printf("������Ҫ������: [����-1�˳�]");
		int value;
		scanf_s("%d", &value);
		if (value == -1) {
			break;
		}
		if (check(data, len, value)) {
			printf("%d�����ݼ�����\n", value);
		}
		else {
			printf("%d�������ݼ�����\n", value);
		}
	}

	system("pause");
	return 0;
}