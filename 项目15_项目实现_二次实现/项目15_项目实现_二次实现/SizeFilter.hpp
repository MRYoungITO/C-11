#pragma once
#ifndef _SIZEFILTER_
#define _SIZEFILTER_

#include <iostream>
#include <set>

using namespace std;


template <class _Ty,
	class _Container = set<_Ty>>

	class SizeFilter {

	typedef SizeFilter<_Ty, _Container> _Myt;
	typedef typename _Container::value_type value_type;
	typedef typename _Container::size_type size_type;

	public:

		SizeFilter() :c() {
			//Ĭ�Ϲ��캯��
		}

		SizeFilter(const _Myt& _Right) :c(_Right.c) {
			//ʹ��SizeFilter���������캯��
			this->c = _Right.c;
			return this->c;
		}

		SizeFilter(const _Container& Cont) :c(Cont.c) {
			//ʹ��ͨ�õ����������캯��
			this->c = Cont.c;
			return this->c;
		}

		_Myt& operator=(const _Myt& _Right) {
			//��ֵ���������
			this->c = _Right.c;
			return (*this);
		}

		bool empty() const {
			//ȷ��������Ԫ���Ƿ�Ϊ��
			return c.empty();
		}

		typename _Container::size_type size() const {
			//ȷ��Ԫ�ظ���
			return c.size();
		}

		bool insert(const value_type& _Val) {
			//�������в���Ԫ��
			typename _Container::iterator cit = c.insert(c.begin(), _Val);
			if (cit != c.end()) {
				cout << "����" << _Val << "�ɹ�!" << endl;
				return true;
			}
			else {
				cout << "����" << _Val << "ʧ��!" << endl;
				return false;
			}
		}

		bool erase(const value_type& _Val) {
			//��������ɾ��Ԫ��
			if (c.erase(_Val) > 0) {
				return true;
			}
			else {
				return false;
			}
		}

		pair<value_type, bool> getMin() {
			pair<value_type, bool> ret;
			typename _Container::iterator cit1 = c.begin();
			if (cit1 != c.end()) {
				ret.first = *cit1;
				ret.second = true;
				return ret;
			}
			else {
				ret.second = false;
				return ret;
			}
		}

		pair<value_type, bool> getMax() {
			pair<value_type, bool> ret;
			typename _Container::iterator cit2 = c.end();
			if (c.size() > 0) {
				ret.first = *(--cit2);
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
