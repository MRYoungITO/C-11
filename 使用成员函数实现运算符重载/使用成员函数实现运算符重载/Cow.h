#pragma once
class Pork;
class Goat;
class Cow
{
public:
	Cow(int weight = 0);

	friend Pork operator+(const Cow& cow1, const Cow& cow2);
	friend Pork operator+(const Cow& cow, const Goat& goat);
	friend Pork operator+(const Goat& goat, const Cow& cow)
	// ʹ�������������ʵ��: һͷţ + һֻţ = ?
	//Pork operator+(const Cow& cow);  // һͷţ + һֻţ 
	// ʹ�������������ʵ��: һͷţ + һֻ�� = ?
	//Pork operator+ (const Goat& goat);  // һͷţ + һֻ��
; private:
	int weight;  //ţ������
};

