#pragma once
#include <string>
using namespace std;

// ������
class Pork
{
public:
	Pork(int weight = 0);
	string description();
private:
	int weight;
};

