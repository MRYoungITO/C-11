#pragma once
#include <string>

using namespace std;

class Engine
{
public:
	Engine(const string& brand, float verison);  //const string& brand, �������岻��ı�����������ֵ
	~Engine();

	string description() const;

private:
	string brand;  //������Ʒ��
	float verison;  //�������ͺ�:  x. x��
};

