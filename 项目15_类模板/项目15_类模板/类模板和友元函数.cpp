#include <iostream>

using namespace std;

template <typename T>
class A
{
public:
	A(T t = 0);

	// ����һ����Ԫ����, ʵ�ֶ���������A�������мӷ�����
	template <typename T>
	friend A<T> addA(const A<T>& a, const A<T>& b);

	T& getT();

	A operator +(const A& other);

	void print();

private:
	T t;
};

template <typename T>
A<T>::A(T t)
{
	this->t = t;
}

template <typename T>
T& A<T>::getT()
{
	return t;
}

template <typename T>
A<T> A<T>::operator+(const A<T>& other) {
	A<T> tmp; //����ڲ����Ϳ�����ʾ����Ҳ���Բ���ʾ
	tmp.t = this->t + other.t;
	return tmp;
}

template <typename T>
void A<T>::print() {
	cout << this->t << endl;
}


// A �����Ԫ����, �������ĺ�����
template <typename T>
A<T> addA(const A<T>& a, const A<T>& b) {
	A<T> tmp;
	cout << "call addA(). . ." << endl;
	tmp.t = a.t + b.t;
	return tmp;
}

int main(void) {

	A<int> a(666), b(888);
	//cout<<a.getT()<<endl;

	A<int> tmp = a + b;
	A<int> tmp1 = addA<int>(a, b);

	tmp.print();
	tmp1.print();
	
	system("pause");
	return 0;
}