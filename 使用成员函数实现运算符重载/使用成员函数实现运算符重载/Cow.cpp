#include "Cow.h"
#include "Pork.h"
#include "Goat.h"

Cow::Cow(int weight)
{
	this->weight = weight;
}

/*
*	һ��ţ��: 2������
*	һ������: 3������
*/
/*
Pork Cow::operator+(const Cow& cow)
{
	int tmp = (this->weight + cow.weight) * 2;
	return Pork(tmp);
}

Pork Cow::operator+(const Goat& goat)
{
	int tmp = this->weight * 2 + goat.getWeight() * 3;
	return Pork(tmp);
}*/
