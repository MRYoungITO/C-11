#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUDSIZE 1024

class ExceptionTest {

};

//1.�����쳣�ӿڵ�����, �ں����������г������׳��������쳣����
//2.���û�а����쳣�ӿ�����. �˺��������׳��κ����͵��쳣
//3.����������������г������׳������������쳣����, ��ô�׳��������͵��쳣�����ܵ��³�����ֹ
//4.���һ�����������׳��κ��쳣, ����ʹ��throw()����

// ʵ���ļ��Ķ����ƿ���							//throw(float, string*, int)
int copyfile2(const char* dest, const char* src) throw() {
	FILE* fp1 = NULL, * fp2 = NULL;

	throw ExceptionTest();

	//ͨ��throw��������һ���쳣��������
	throw 0.01f;
	//rb ֻ����ʽ��һ���������ļ�, ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");

	if (fp1 == NULL) {
		throw new string("�ļ�������");
	}

	//wb ��ֻд�ķ�ʽ�򿪻��½�һ���������ļ�; ֻ����д����
	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUDSIZE];
	int readlen, writelen;

	while ((readlen = fread(buffer, 1, BUFSIZ, fp1)) > 0) {
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
	try {
		copyfile2(dest, src);
	}
	catch (float e) {
		//throw ;
		printf("copyfile1 - catch...\n");

		//��ʾ: �����˵��쳣, ���ǿ�����catch�����һ����֧, ʹ��throw�﷨, �����������throw
		throw e;
	}

	return 0;
}

int main(void) {
	int ret = 0;

	//����Ҫ��׽�쳣�ĵط�, �������׳��쳣�ĳ����Ƕ��try��֮��
	//�������ĳ���˳��ִ�е���try���, Ȼ��ִ��try��{}�ڵı�����,
	//����ڱ�����ִ���ڼ�û�������쳣,name����try����catch�Ӿ�Ͳ�ִ��, �����try����������һ��catch�Ӿ�����������ִ����ȥ
	try {//������
		printf("��ʼִ�� copyfile...\n");
		ret = copyfile1("D:/CPP_Project_learning/��Ŀ15_��ͳ���������/��Ŀ15_��ͳ���������/des.txt", "D:/CPP_Project_learning/��Ŀ15_��ͳ���������/��Ŀ15_��ͳ���������/src.txt");
		printf("ִ�� copyfile ���\n");
	}
	//catch�Ӿ䰴����try�����ֵ�˳�򱻼��, ƥ���catch�Ӿ佫���񲢰�catch�Ӿ��еĴ��봦���쳣
	catch (const int error) {
		printf("�����쳣��!%d\n", error);
	}
	catch (const string* error) {
		printf("��׽���ַ����쳣: %s\n", error->c_str());
		delete error;
	}
	catch (const float error) {
		printf("�����쳣��!%f\n", error);
	}
	catch (...) {
		printf("catch ... \n");
	}

	// ���û���ҵ�ƥ��, ��ȱʡ�����ǵ���abort��ֹ����

	/*if (ret != 0) {
		switch (ret) {
		case -1:
			printf("��Դ�ļ�ʧ��\n");
			break;
		case -2:
			printf("��Ŀ���ļ�ʧ��\n");
			break;
		case -3:
			printf("�����ļ�ʱ����\n");
			break;
		default:
			printf("����δ֪�����!\n");
			break;
		}

	}*/
	system("pause");
	return 0;
}