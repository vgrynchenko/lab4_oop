#pragma once
#include <iostream>
#include "Nodes.h"
#include "JavaIteratorInterface.h"
#include <algorithm>

using namespace std;


template<class T> class Container;
template <class T>
class Container 
{
public:
	virtual JavaIteratorInterface<T&>* CreateIter() = 0;
	virtual JavaIteratorInterface<const T&>* CreateConstIter() const = 0;
	bool operator==(Container<T> const&) const;
	virtual int Size() const = 0;
	virtual bool IsEmpty() const = 0;
	std::string ToString() const;
	//void SelectionSort();
	virtual ~Container() {};

};
template<class T>
ostream& operator<<(ostream&, const Container<T>&);

template <class T>
class PushPopContainer :
	public virtual Container<T> {
public:
	virtual bool Push(const T&) = 0;
	virtual T Pop() = 0;
	virtual T& Peek() = 0;
	virtual ~PushPopContainer() {};
};
template <class T>
class Deque :

	public virtual Container<T> 
{
public:
	virtual bool PushFront(const T&) = 0;
	virtual bool PushBack(const T&) = 0;
	virtual T PopFront() = 0;
	virtual T PopBack() = 0;
	virtual T& PeekFront() = 0;
	virtual T& PeekBack() = 0;
	virtual ~Deque() {};
};
template <class T>
class IndexedContainer :

	public virtual Container<T> 
{
public:
	virtual T& Get(int index) const = 0;
	virtual void Set(int, const T&) = 0;
	T operator[](int);
	virtual ~IndexedContainer() {};
};
template <class T>
class InsertableContainer :
	public	virtual IndexedContainer<T> 
{
public:
	virtual bool Insert(int, const T&) = 0;
	virtual T Remove(int) = 0;
	virtual ~InsertableContainer() {};
};

template<class T>
std::string Container<T>::ToString() const
{
	JavaIteratorInterface<const T&>* StringIter = this->CreateConstIter();
	std::string result = "";
	while (StringIter->hasNext())
	{
		result += std::to_string(StringIter->Next()) + " ";
	}
	return result;
}


template<>
std::string Container<std::string>::ToString() const
{
	JavaIteratorInterface<const string&>* StringIter = this->CreateConstIter();
	std::string result = "";
	while (StringIter->hasNext())
	{
		result += StringIter->Next() + " ";
	}
	return result;
}

template <class T>
bool Container<T>::IsEmpty() const
{
	return !Size();
}
template<class container>
void SelectionSort(container& sortContainer)
{
	int MinIndex = 0;
	container::iterator *Iter = sortContainer.CreateIter(), *MinIter, *insIter;
	for (int i = 0; i < sortContainer.Size(); i++)
	{
		insIter = sortContainer.CreateIter();
		Iter = sortContainer.CreateIter();
		for (int j = 0; j < i; j++)
		{
			insIter->Next();
			Iter->Next();
		}
		Iter->Next();
		MinIndex = i;
		for (int j = i + 1; j < sortContainer.Size(); j++)
		{
			MinIter = sortContainer.CreateIter();
			for (int min_i = 0; min_i < MinIndex; min_i++)
				MinIter->Next();
			if (MinIter->Next() > Iter->Next())
				MinIndex = j;
		}
		MinIter = sortContainer.CreateIter();
		for (int min_i = 0; min_i < MinIndex; min_i++)
			MinIter->Next();
		swap(MinIter->Next(), insIter->Next());
	}
}

template <class T>
bool Container<T>::operator==(Container<T> const& other) const 
{
	if (this->Size() != other.Size())
		return false;
	JavaIteratorInterface<T const&> * thisIter = this->CreateConstIter(), *otherIter = other.CreateConstIter();
	while (thisIter->hasNext()) 
	{
		if (thisIter->Next() != otherIter->Next())
			return false;
	}
	return true;
}
template<class T>
T IndexedContainer<T>::operator[](int index) 
{ 
	return this->Get(index); 
}

template <class T>
ostream& operator<<(ostream& os, Container<T>& container) 
{
	os << container.ToString();
	return os;
}

