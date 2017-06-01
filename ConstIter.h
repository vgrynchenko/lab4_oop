#pragma once
#include <iterator>
#include "Fibonacci.h"
template <class T>
class ConstIter : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
	T val1, val2;
	int index, end_index;
public:
	ConstIter(const Fibonacci<T>&);
	ConstIter(const T&, const T&, int, int);
	ConstIter(const ConstIter<T>&);
	ConstIter<T>& operator=(const ConstIter<T>&);
	bool operator==(const ConstIter<T>&);
	bool operator!=(const ConstIter<T>&);
	bool operator>(const ConstIter<T>&);
	bool operator<(const ConstIter<T>&);
	bool operator<=(const ConstIter<T>&);
	bool operator>=(const ConstIter<T>&);
	T operator*();
	T* operator->();
	ConstIter<T>& operator++();//prefix
	ConstIter<T> operator++(int);//postfix
	ConstIter<T>& operator--();//prefix
	ConstIter<T> operator--(int);//postfix
	ConstIter<T>& operator+=(int);
	ConstIter<T>& operator-=(int);
	ConstIter<T> operator+(int);
	ConstIter<T> operator-(int);
	~ConstIter();
	
};

//итератор на начальный элемент Фибоначчи
template<class T>
inline ConstIter<T>::ConstIter(const Fibonacci<T>& fibonacci)
{
	index = 0;
	end_index = fibonacci.size_container;
	val1 = fibonacci.first_def;//текущее значение
	val2 = fibonacci.second_def;//следующее значение
}

template<class T>
inline ConstIter<T>::ConstIter(const T& val1, const T& val2, int index, int end_index)
{
	if (index < 0 || index > end_index)
		throw 2;
	this->end_index = end_index;
	this->val1 = val1;
	this->val2 = val2;
	this->index = index;
}

template<class T>
inline ConstIter<T>::ConstIter(const ConstIter<T>& iter)
{
	val1 = iter.val1;
	val2 = iter.val2;
	index = iter.index;
	end_index = iter.end_index;
}

template<class T>
inline ConstIter<T>& ConstIter<T>::operator=(const ConstIter<T>& iter)
{
	val1 = iter.val1;
	val2 = iter.val2;
	index = iter.index;
	end_index = iter.end_index;
	return *this;
}

template<class T>
inline bool ConstIter<T>::operator==(const ConstIter<T>& iter)
{
	return (val1 == iter.val1 && val2 == iter.val2 && index == iter.index && end_index == iter.end_index);
}

template<>
inline bool ConstIter<std::string>::operator==(const ConstIter<std::string>& iter)
{
	return (!val1.compare(iter.val1) && !val2.compare(iter.val2) && index == iter.index && end_index == iter.end_index);
}

template<class T>
inline bool ConstIter<T>::operator!=(const ConstIter<T>& iter)
{
	return (val1 != iter.val1 || val2 != iter.val2 || index != iter.index || end_index != iter.end_index);
}

template<>
inline bool ConstIter<std::string>::operator!=(const ConstIter<std::string>& iter)
{
	return (val1.compare(iter.val1) || val2.compare(iter.val2) || index != iter.index || end_index != iter.end_index);
}

template<class T>
inline bool ConstIter<T>::operator>(const ConstIter<T>& iter)
{
	return (index > iter.index);
}

template<class T>
inline bool ConstIter<T>::operator<(const ConstIter<T>& iter)
{
	return (index < iter.index);
}

template<class T>
inline bool ConstIter<T>::operator<=(const ConstIter<T>& iter)
{
	return (*this == iter) || (*this < iter);
}

template<class T>
inline bool ConstIter<T>::operator>=(const ConstIter<T>& iter)
{
	return (*this == iter) || (*this > iter);
}

template<class T>
inline T ConstIter<T>::operator*()
{
	if (!index)
		return val1;
	else if (index == 1)
		return val2;
	else if (index == end_index)
		throw 2;
	else
	{
		T iter_res = val1, current = val1, next = val2;
		for (int i = 1; i < index; i++) 
		{
			iter_res = current + next;
			current = next;
			next = iter_res;
		}
		return iter_res;
	}
}

template<class T>
inline T * ConstIter<T>::operator->()
{
	if (!index)
		return &val1;
	else if (index == 1)
		return &val2;
	else if (index == end_index)
		throw 2;
	else
	{
		T iter_res = val1, current = val1, next = val2;
		for (int i = 1; i < index; i++) 
		
			iter_res = current + next;
			current = next;
			next = iter_res;
		}
		return &iter_res;
}


template<class T>
inline ConstIter<T>& ConstIter<T>::operator++()
{
	if (index == end_index)
		throw 2;
	++index;
	return *this;
}

template<class T>
inline ConstIter<T> ConstIter<T>::operator++(int)
{
	if (index == end_index)
		throw 2;
	index++;
	return *this;
}

template<class T>
inline ConstIter<T>& ConstIter<T>::operator--()
{
	if (index == 0)
		throw 2;
	--index;
	return *this;
}

template<class T>
inline ConstIter<T> ConstIter<T>::operator--(int)
{
	if (index == 0)
		throw 2;
	index--;
	return *this;
}


template<class T>
inline ConstIter<T>& ConstIter<T>::operator+=(int shift)
{
	if (index + shift < 0 || index + shift > end_index)
		throw 2;
	index += shift;
	return *this;
}

template<class T>
inline ConstIter<T>& ConstIter<T>::operator-=(int shift)
{
	if (index - shift < 0 || index - shift > end_index)
		throw 2;
	index -= shift;
	return *this;
}

template<class T>
inline ConstIter<T> ConstIter<T>::operator+(int shift)
{
	ConstIter<T>& iter_res(*this);
	iter_res += shift;
	return iter_res;
}

template<class T>
inline ConstIter<T> ConstIter<T>::operator-(int shift)
{
	ConstIter<T>& iter_res(*this);
	iter_res -= shift;
	return iter_res;

}

template<class T>
inline ConstIter<T>::~ConstIter() {}
