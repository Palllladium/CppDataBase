#pragma once
#include "Unit.hpp"

template<class T>
class List
{
private:
	Unit<T>* head;
	Unit<T>* tail;
	int size;
public:
	List();
	~List();

	Unit<T>* getTail();
	Unit<T>* getHead();
	int getSize();

	bool is_empty();
	void push_back(T value);
	void pop_front();
	void pop_back();
	void clear();
	int erase(Unit<T>* value);

	int listFromFile(T& value, string path);
	int listToFile(T& value, string path);

	Unit<T>* _search_ID(int ID);
	Unit<T>* _search_ID(string ID);

	Unit<T>* _search_FullName(string value);
	Unit<T>* _search_Title(string value);
	Unit<T>* _search_Price(string value);

};

template<class T>
inline List<T>::List()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

template<class T>
inline List<T>::~List()
{
	this->clear();
}


template<class T>
inline Unit<T>* List<T>::getHead()
{
	return this->head;
}

template<class T>
inline Unit<T>* List<T>::getTail()
{
	return this->tail;
}

template<class T>
inline int List<T>::getSize()
{
	return this->size;
}

template<class T>
inline bool List<T>::is_empty()
{
	return this->head == NULL;
}

template<class T>
inline void List<T>::push_back(T value)
{
	Unit<T>* newUnit = new Unit<T>(value);
	if (is_empty()) {
		this->head = this->tail = newUnit;
	}
	else {
		newUnit->setPrev(this->tail);
		this->tail->setNext(newUnit);
		this->tail = newUnit;
	}
	this->size++;
}

template<class T>
inline void List<T>::pop_front()
{
	if (is_empty())
		cout << "list is empty\n";
	else {
		Unit<T>* temp;
		temp = this->head;
		this->head = this->head->getNext();
		//head->setPrev(NULL);
		delete temp;
		temp = nullptr;
		size--;
	}
}

template<class T>
inline void List<T>::pop_back()
{
	if (is_empty())
		cout << "list is empty\n";

	else {
		Unit<T>* temp;
		temp = this->tail;
		this->tail = temp->getPrev();
		this->tail->setNext(NULL);
		delete temp;
		temp = nullptr;
		size--;
	}
}

template<class T>
inline void List<T>::clear()
{
	while (!this->is_empty())
		this->pop_front();
}

template<class T>
inline int List<T>::erase(Unit<T>* value)
{
	if (is_empty()) {
		cout << "list is empty\n";
		return 500;
	}
	if (value == this->getHead()) {
		this->pop_front();
		return 201;
	}
	if (value == this->getTail()) {
		this->pop_back();
		return 202;
	}
	Unit<T>* ptr = this->getHead()->getNext();
	while (ptr != value && ptr != NULL) {
		ptr = ptr->getNext();
	}
	if (ptr == NULL)
		return 404;
	ptr->getPrev()->setNext(ptr->getNext());
	ptr->getNext()->setPrev(ptr->getPrev());
	delete ptr;
	ptr = nullptr;
	size--;
	return 200;
}

template<class T>
inline Unit<T>* List<T>::_search_ID(int ID)
{
	Unit<T>* ptr;
	ptr = this->getHead();
	while (ptr->getData().get_ID() != ID && ptr->getNext() != NULL)
		ptr = ptr->getNext();
	if (ptr->getData().get_ID() != ID && ptr->getNext() == NULL) {
		cout << "search of " << ID << " element failed. Check corresponding database file.\n";
		return NULL;
	}
	else return ptr;
}

template<class T>
inline Unit<T>* List<T>::_search_ID(string ID)
{
	int sID = stoi(ID);
	return this->_search_ID(sID);
}

template<class T>
inline Unit<T>* List<T>::_search_FullName(string value)
{
	Unit<T>* ptr;
	ptr = this->getHead();
	while (ptr->getData().get_FullName() != value && ptr->getNext() != NULL)
		ptr = ptr->getNext();
	if (ptr->getData().get_FullName() != value && ptr->getNext() == NULL) {
		cout << "search of " << value << " element failed. Check corresponding database file.\n";
		return NULL;
	}
	else return ptr;
}

template<class T>
inline Unit<T>* List<T>::_search_Title(string value)
{
	Unit<T>* ptr;
	ptr = this->getHead();
	while (ptr->getData().get_Title() != value && ptr->getNext() != NULL)
		ptr = ptr->getNext();
	if (ptr->getData().get_Title() != value && ptr->getNext() == NULL) {
		cout << "search of " << value << " element failed. Check corresponding database file.\n";
		return NULL;
	}
	else return ptr;
}

template<class T>
inline Unit<T>* List<T>::_search_Price(string value)
{
	Unit<T>* ptr;
	ptr = this->getHead();
	while (ptr->getData().get_Price() != value && ptr->getNext() != NULL)
		ptr = ptr->getNext();
	if (ptr->getData().get_Price() != value && ptr->getNext() == NULL) {
		cout << "search of " << value << " element failed. Check corresponding database file.\n";
		return NULL;
	}
	else return ptr;
}


template<class T>
inline int List<T>::listFromFile(T& value, string path)
{
	fstream fin;
	fin.open(path);
	if (fin.is_open() == false)
		return 500;
	while (fin.eof() == false)
	{
		value.fillElement(fin);
		this->push_back(value);
	}
	fin.close();
	return 200;
}

template<class T>
inline int List<T>::listToFile(T& value, string path)
{
	fstream fout;
	Unit<T>* ptr;
	fout.open(path, ios::out);
	fout.clear();
	if (fout.is_open() == false)
		return 500;
	ptr = this->getHead();
	while (ptr != NULL)
	{
		ptr->getData().printElement(fout);
		ptr = ptr->getNext();
		if (ptr != NULL)
			fout << "\n";
	}
	fout.close();
	return 200;
}
