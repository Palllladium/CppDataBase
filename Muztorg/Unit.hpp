#pragma once
#include "include.h"

using namespace std;

template <class T>
class Unit
{
private:
	T data;
	Unit* next;
	Unit* prev;
public:
	Unit();
	Unit(T value);

	T getData();
	Unit<T>* getNext();
	Unit<T>* getPrev();

	void setNext(Unit* value);
	void setPrev(Unit* value);
	void setData(T value);
};

template<class T>
inline Unit<T>::Unit()
{
	this->data = 0;
	this->next = NULL;
	this->prev = NULL;
}

template<class T>
inline Unit<T>::Unit(T value)
{
	this->data = value;
	this->next = NULL;
	this->prev = NULL;
}

template<class T>
inline T Unit<T>::getData()
{
	return data;
}

template<class T>
inline Unit<T>* Unit<T>::getNext()
{
	return next;
}

template<class T>
inline Unit<T>* Unit<T>::getPrev()
{
	return prev;
}

template<class T>
inline void Unit<T>::setNext(Unit* value)
{
	this->next = value;
}

template<class T>
inline void Unit<T>::setPrev(Unit* value)
{
	this->prev = value;
}

template<class T>
inline void Unit<T>::setData(T value)
{
	this->data = value;
}