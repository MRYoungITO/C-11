#include <iostream>
#include <Windows.h>
#include "��ģ�庯����ͷ�ļ��ֿ�.h"

using namespace std;

template <typename T>
A<T>::A(T t) {
	this->t = t;
}

template <typename T>
T& A<T>::getT() {
	return t;
}

template <typename T>
A<T> A<T>::operator+(const A<T>& other) {
	A<T> tmp;  // ����ڲ����Ϳ�����ʾ����,Ҳ���Բ���ʾ
	tmp.t = this->t + other.t;
	return tmp;
}

template <typename T>
void A<T>::print() {
	cout << this->t << endl;
}