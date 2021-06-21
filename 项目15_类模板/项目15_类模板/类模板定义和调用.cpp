#include <iostream>

using namespace std;


// �̳��и������ģ����Ľ�����
// 1.������һ����, ������ģ����, ����ͨ�̳е��÷�����
// 2.������һ����, ������ģ����, �̳�ʱ��������������ʵ������������Ͳ���
// 3. ��������඼��ģ����, ��������Ϳ��Դ��ݵ�������

//class B {
//public:
//	B(int b) {
//		this->b = b;
//	}
//
//private:
//	int b;
//};

template <typename T>
class A /*: public B*/
{
public:
	A(T t = 0); /*: B(0)*/
	// ��Ա��������ֵ������������
	T& getT();
	A operator+(const A& other);
	void print();

private:
	T t;
};

//class A
//{
//public:
//	A(int t = 0);
//	// ��Ա��������ֵ������������
//	int& getT();
//	A operator+(const A& other);
//	void print();
//
//private:
//	int t;
//};

template <typename T>
A<T>::A(T t) {
	this->t = t;
}

template <typename T>
T &A<T>::getT() {
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

//template <typename Tb>
//class B : public A<int> {
//	public:
//	B(Tb b) : A<Tb>(b) {
//		this->b = b;
//	}
//
//private:
//	Tb b;
//};
//
//void printA(A<int> &a) {
//	cout << a.getT() << endl;
//}

int main(void) {
	// 1.ģ���ඨ�������, ������ʾָ������
	// 2.ģ�������ʹ���˹��캯��, ��������ǰ����Ĺ��캯���ĵ��ù���
	A<int> a(666), b(888);
	//cout << a.getT() << endl;

	A<int> tmp = a + b;

	tmp.print();

	//B<int> b(888);
	//cout << "b(888) : "<< b.getT() << endl;

	// ģ������Ϊ��������
	//printA(a);

	system("pause");
	return 0;
}