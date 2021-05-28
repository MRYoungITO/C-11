#include <iostream>
#include "ComputerService.h"
#include "Computer.h"

void ComputerService::upgrade(Computer* computer)
{
	computer->cpu = "i9";
}

void ComputerService::clean(Computer* computer)
{
	cout << "���ڶԵ���ִ������[CPU:"
		<< computer->cpu << "]. . ."
		<< endl;
}

void ComputerService::kill(Computer* computer)
{
	cout << "���ڶԵ���ִ��ɱ��[CPU:"
		<< computer->cpu << "]. . ."
		<< endl;
}
