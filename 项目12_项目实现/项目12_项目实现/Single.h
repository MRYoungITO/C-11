#pragma once
#include <string>

using namespace std;

class Single
{
public:
	Single();
	Single(string name, int age);
	~Single();
	int getAge()const;
	string getName()const;

protected:
	int age;
	string name;
};