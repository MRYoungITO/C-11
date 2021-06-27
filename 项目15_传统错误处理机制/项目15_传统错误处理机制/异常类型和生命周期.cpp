#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024


//ʵ���ļ��Ķ����ƿ���

//��һ�������throw ��ͨ���ͣ��ͺ������ش�ֵ��һ����
int copyfile2(const char* dest, const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;

	//rb ֻ����ʽ��һ���������ļ���ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		//int ret = -1;
		char ret = 'a';
		throw ret;
	}

	//wb ��ֻд�ķ�ʽ�򿪻��½�һ���������ļ���ֻ����д���ݡ�
	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//����������ݣ������0
	while ((readlen = fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen) {
			throw - 3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}

int copyfile1(const char* dest, const char* src) {
	return copyfile2(dest, src);
}

void main() {
	int ret = 0;


	try {//������
		//printf("��ʼִ�� copyfile1...\n");
		ret = copyfile1("D:/CPP_Project_learning/��Ŀ15_��ͳ���������/��Ŀ15_��ͳ���������/dest.txt", "D:/CPP_Project_learning/��Ŀ15_��ͳ���������/��Ŀ15_��ͳ���������/src.txt");
		//printf("ִ�� copyfile1 ���\n");

	}
	catch (int error) {
		printf("�����쳣����%d\n", error);
	}
	catch (char error) {
		printf("�����쳣����%c\n", error);
	}

	system("pause");
}