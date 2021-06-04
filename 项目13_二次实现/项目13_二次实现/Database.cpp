#include <fstream>
#include <iostream>
#include <string>
#include "Database.h"
#include "Girl.h"
#include "Boy.h"

#define BOYS_FILE "boys.txt"
#define GIRLS_FILE "girls.txt"

Database::Database()
{

}

void Database::init()
{
	// ��֮ǰ�Ѿ�������ļ���, ��ȡ�û���Ϣ, 
	// ������ʼ���ڲ�����boys��girls
	initBoysFromFile();
	initGirlsFromFile();
}

void Database::autoPair()
{
	cout << endl << "�Զ���Խ��: " << endl;
	string line(100, '-');
	cout << line << endl;

	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) &&
				girls[j].satisfied(boys[i])) {
				cout << boys[i].description() << endl;
				cout << girls[j].description() << endl;
				cout << line << endl;
			}
		}
	}

	for (int i = 0; i < girls.size(); i++) {
		for (int j = 0; j < boys.size(); j++) {
			if (girls[i].satisfied(boys[j]) &&
				boys[j].satisfied(girls[i])) {
				cout << girls[i].description() << endl;
				cout << boys[j].description() << endl;
				cout << line << endl;
			}
		}
	}
}

void Database::autoPairBest()
{
	cout << endl << "�Զ���Ѱ���: " << endl;
	string line(100, '-');
	cout << line << endl;

	for (int i = 0; i < boys.size(); i++) {
		Girl* girlBest = NULL;
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) &&
				girls[j].satisfied(boys[i])) {
				if (!girlBest) {
					girlBest = &girls[j];
				}
				else if (girls[j] > *girlBest) {
					girlBest = &girls[j];
				}
			}
		}
		if (girlBest) {
			cout << boys[i]<< endl;
			cout << *girlBest << endl;
			cout << line << endl;
		}
	}

	for (int i = 0; i < girls.size(); i++) {
		Boy* boyBest = NULL;
		for (int j = 0; j < boys.size(); j++) {
			if (girls[i].satisfied(boys[j]) &&
				boys[j].satisfied(girls[i])) {
				if (!boyBest) {
					boyBest = &boys[j];
				}
				else if (boys[j] > *boyBest) {
					boyBest = &boys[j];
				}
			}
		}
		if (boyBest) {
			cout << girls[i] << endl;
			cout << *boyBest << endl;
			cout << line << endl;
		}
	}
}

void Database::print()
{
	cout << "�мα���Ϣ: \n";
	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}

	cout << "\nŮ�α���Ϣ: \n";
	for (int i = 0; i < girls.size(); i++) {
		cout << girls[i].description() << endl;
	}
}

void Database::addOne(Boy& boy)
{
	boys.push_back(boy);

	cout << endl << "�Զ���Խ��: " << endl;
	string line(100, '-');
	cout << line << endl;

	for (int j = 0; j < girls.size(); j++) {
		if (boy.satisfied(girls[j]) &&
			girls[j].satisfied(boy)) {
			cout << boy.description() << endl;
			cout << girls[j].description() << endl;
			cout << line << endl;
		}
	}
}

void Database::addOne(Girl& girl)
{
	girls.push_back(girl);

	cout << endl << "�Զ���Խ��: " << endl;
	string line(100, '-');
	cout << line << endl;

	for (int j = 0; j < boys.size(); j++) {
		if (girl.satisfied(boys[j]) &&
			boys[j].satisfied(girl)) {
			cout << girl.description() << endl;
			cout << boys[j].description() << endl;
			cout << line << endl;
		}
	}
}

void Database::initBoysFromFile()
{
	// ���ļ�  ���ļ�����  ��ʼ��boys
	ifstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {
		// �ʼʱ, û���ļ�!
		// �������������:
		// �ʼû���ļ�ʱ, ���û���������û�����
		cout << "===��������û����мα�������===" << endl;
		Boy::inputBoys(this->boys);
		saveBoys();
		stream.close();
		return;
	}

	// boys.txt �򿪳ɹ�
	while (1) {
		string line;
		char name[64] = "";
		int salary;
		int age;

		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		// ����������һ������line
		//to do.
		// �ļ��ĸ�ʽ:   �Ա�:��\t\t\t����:Rock\t\t\tн��:35000\t\t\t����:39

		int ret = sscanf_s(line.c_str(), "�Ա�:�� ����:%s н��:%d ����:%d",
			name, sizeof(name), &salary, &age);
		if (ret <= 0) {
			cout << "�мα����ݿ��ʽƥ��ʧ��" << endl;
			exit(1);
		}

		// ʹ�ö�����һ����������Ϣ, ����һ��Boy����, ����ӵ�boys
		boys.push_back(Boy(age, string(name), salary));
	}
}

void Database::initGirlsFromFile()
{
	// ���ļ�  ���ļ�����  ��ʼ��boys

	ifstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) {
		// �ʼʱ, û���ļ�!
		// �������������:
		// �ʼû���ļ�ʱ, ���û���������û�����
		cout << "===��������û���Ů�α�������===" << endl;
		Girl::inputGirls(this->girls);
		saveGirls();
		stream.close();
		return;
	}

	// girls.txt �򿪳ɹ�
	while (1) {
		string line;
		char name[64] = "";
		int yanzhi;
		int age;

		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		// ����������һ������line
		//to do.
		// �ļ��ĸ�ʽ:   �Ա�:Ů\t\t\t����:����\t\t\t��ֵ:90\t\t\t����:25

		int ret = sscanf_s(line.c_str(), "�Ա�:Ů ����:%s ��ֵ:%d ����:%d",
			name, sizeof(name), &yanzhi, &age);
		if (ret <= 0) {
			cout << "Ů�α����ݿ��ʽƥ��ʧ��" << endl;
			exit(1);
		}

		// ʹ�ö�����һ����������Ϣ, ����һ��Boy����, ����ӵ�boys
		girls.push_back(Girl(age, string(name), yanzhi));
	}
}

void Database::saveBoys()
{
	// ��boys�е����е�������Ϣд���ļ�
	ofstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {
		cout << BOYS_FILE << "д��ʧ��" << endl;
		exit(1);
	}
	for (int i = 0; i < boys.size(); i++) {
		stream << boys[i].description() << endl;
	}
	stream.close();
}

void Database::saveGirls()
{
	// ��girls�е����е�������Ϣд���ļ�
	ofstream stream;
	stream.open(GIRLS_FILE);
	if (!stream.is_open()) {
		cout << GIRLS_FILE << "д��ʧ��" << endl;
		exit(1);
	}
	for (int i = 0; i < girls.size(); i++) {
		stream << girls[i].description() << endl;
	}
	stream.close();
}
