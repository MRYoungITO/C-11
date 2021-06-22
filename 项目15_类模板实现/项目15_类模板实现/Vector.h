#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Vector {
public:
	Vector(int size = 128);  //���캯��
	Vector(const Vector& object);  //�������캯��

	int getLength();  //��ȡ�ڲ��洢��Ԫ�ظ���

	template <typename T>
	friend ostream& operator<<(const ostream& os, const Vector<T>& object);

	//Vector<int> a1, a2;  a1[0]
	T& operator[](int index);

	//ʵ��=����������
	//a1 = a2 = a3;
	Vector& operator=(const Vector& object);

	~Vector();  //��������

private:
	T* m_base;
	int m_len;
};

template <typename T>
ostream& operator<<(const ostream& os, const Vector<T>& object);