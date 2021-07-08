#pragma once
#ifndef _SIZEFILTER_
#define _SIZEFILTER_

#include <iostream>
#include <set>

using namespace std;

template <class _Ty,
	class _Container = set<_Ty>>

	class sizeFilter {
	public:

		typedef sizeFilter<_Ty, _Container> _Myt;
		typedef typename _Container::size_type size_type;
		typedef typename _Container::value_type value_type;

		sizeFilter() :c() {
			// Ĭ�Ϲ��캯��, ��ʼ����������
		}

		sizeFilter(const _Myt& _Right) :c(_Right.c) {
			// ���캯��, ͨ��ָ���ض���sizeFilter��������
		}

		sizeFilter(const _Container& _Cont) :c(_Cont.c) {
			//���캯��, ͨ��ָ���ض�����������
		}

		_Myt& operator=(const _Myt& _Right) { //A = B = C = D
			//ʹ����һ��sizeFilter ��ֵ
			this->c = _Right.c;
			return (*this);
		}

		bool empty() const {
			//���� SizeFilter �Ƿ�Ϊ��
			return (c.empty());
		}

		size_type size() const {
			//����SizeFilter�ĳ���
			return (c.size());
		}

		bool insert(const value_type& _Val) {
			//����Ԫ��
			pair<_Container::iterator, bool> ret = c.insert(_Val);
			if (ret.second) {
				cout << "����" << _Val << "�ɹ�!" << endl;
				return true;
			}
			else {
				cout << "����" << _Val << "ʧ��!" << endl;
				return false;
			}

		}

		bool erase(const value_type& _val) {
			// ����Ԫ��
			if (c.erase(_val) > 0) {
				return true;
			}
			else {
				return false;
			}
		}

		pair<value_type, bool> getMin() {
			//��ȡ��Сֵ
			pair<value_type, bool> ret;
			typename _Container::iterator min = c.begin();

			if (min != c.end()) {	//������Сֵ
				ret.first = *min;
				ret.second = true;
				return ret;
			}
			else {
				ret.second = false;
				return ret;
			}
		}

		pair<value_type, bool> getMax() {
			//��ȡ���ֵ
			pair<value_type, bool> ret;
			typename _Container::iterator end = c.end();
			if (c.size()>0) {	//������Сֵ
				ret.first = *(--end);
				ret.second = true;
				return ret;
			}
			else {
				ret.second = false;
				return ret;
			}
		}

	protected:
		_Container c;
};


#endif // !_SIZEFILTER_
