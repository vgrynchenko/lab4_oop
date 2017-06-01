#pragma once
#include <string>
template <class T> class ConstIter;

template <class T>
class Fibonacci
{
private:
	T first_def, second_def;
	int size_container;
	const int val_zero = 0, val_one = 1;
	const std::string val_a = "a", val_b = "b";
public:
	friend class ConstIter<T>;
	typedef ConstIter<T> const_iterator;
	Fibonacci(const T&, const T&, int);
	Fibonacci(int);
	const_iterator cbegin();
	const_iterator cend();
	T at(int);
	void resize(int);
	int size();
	~Fibonacci();
};

template<class T>
inline Fibonacci<T>::Fibonacci(const T & first_def, const T & second_def, int size_container)
{
	if (size_container < 2)
		throw 1;
	this->first_def = first_def;
	this->second_def = second_def;
	this->size_container = size_container;
}

template<class T>
inline Fibonacci<T>::Fibonacci(int size_container)
{
	if (size_container < 2)
		throw 1;
	this->size_container = size_container;
	first_def = val_zero;
	second_def = val_one;
}


template<>
inline Fibonacci<std::string>::Fibonacci(int size_container)
{
	if (size_container < 2)
		throw 1;
	this->size_container = size_container;
	first_def += val_a;
	second_def += val_b;
}

template<class T>
inline void Fibonacci<T>::resize(int size_container)
{
	if (size_container < 2)
		throw 1;
	this->size_container = size_container;
}

template<class T>
inline int Fibonacci<T>::size()
{
	return size_container;
}

template<class T>
inline Fibonacci<T>::~Fibonacci() {}

#include "ConstIter.h"

template<class T>
inline typename Fibonacci<T>::const_iterator Fibonacci<T>::cbegin()
{
	return const_iterator(first_def, second_def, 0, size_container);
}

template<class T>
inline typename Fibonacci<T>::const_iterator Fibonacci<T>::cend()
{
	return (const_iterator(first_def, second_def, 0, size_container) + size_container);
}

template<class T>
inline T Fibonacci<T>::at(int index)
{
	if (index >= size() || index < 0)
		throw 2;
	return *(cbegin() + index);
}
