#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data(data), next(next) {}
};

template<typename T>
class FwdList
{
public:
	FwdList() = default;
	~FwdList();
	bool empty() const;
	void print() const;

	void addHead(const T& data);
	void removeHead();

	FwdList<T> clone() const;

	FwdList operator+(const FwdList& other) const;

	FwdList operator*(const FwdList& other) const;

private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;

	void clear();
};

template<typename T>
FwdList<T>::~FwdList()
{
	clear();
}

template<typename T>
void FwdList<T>::clear()
{
	while (!empty()) {
		removeHead();
	}
}

template<typename T>
FwdList<T> FwdList<T>::clone() const
{
	FwdList<T> newList;
	if (empty()) return newList;

	Node<T>* tmp = head;
	while (tmp) {
		newList.addHead(tmp->data);
		tmp = tmp->next;
	}
	return newList;
}

template<typename T>
FwdList<T> FwdList<T>::operator+(const FwdList<T>& other) const
{
	FwdList<T> result = this->clone();
	Node<T>* tmp = other.head;
	while (tmp) {
		result.addHead(tmp->data);
		tmp = tmp->next;
	}
	return result;
}

template<typename T>
FwdList<T> FwdList<T>::operator*(const FwdList<T>& other) const
{
	FwdList<T> result;
	Node<T>* tmp = head;
	while (tmp) {
		Node<T>* otherTmp = other.head;
		while (otherTmp) {
			if (tmp->data == otherTmp->data) {
				result.addHead(tmp->data);
				break;
			}
			otherTmp = otherTmp->next;
		}
		tmp = tmp->next;
	}
	return result;
}

template<typename T>
inline bool FwdList<T>::empty() const
{
	return head == nullptr;
}

template<typename T>
inline void FwdList<T>::print() const
{
	if (empty()) {
		cout << "List is empty" << endl;
		return;
	}
	auto tmp = head;
	cout << "List :\t";
	while (tmp != nullptr) {
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	Node<T>* tmp = new Node<T>(data, head);
	if (empty())
		tail = tmp;
	head = tmp;
	++size;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (empty())
		return;
	auto tmp = head;
	head = head->next;
	if (empty())
		tail = head;
	delete tmp;
	--size;
}
