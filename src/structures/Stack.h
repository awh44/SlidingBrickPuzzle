#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>

#include "Collection.h"
#include "Node.h"

template <class T>
class Stack : public Collection<T>
{
	public:
		Stack(); //"MAKENULL" substitute
		~Stack();
		T top();
		void push(T x);
		void pop();
		bool empty();
		void empty_stack();

		T get();
		void add(T x);
		void remove();
		void empty_collection();

	private:
		Node<T> *head_;
};

template <class T>
Stack<T>::Stack()
{
	head_ = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	empty_stack();
}

template <class T>
T Stack<T>::top()
{
	return (*head_).get_data();
}

template <class T>
void Stack<T>::pop()
{
	Node<T> *temp = head_;
	head_ = head_->get_next();
	delete temp;
}

template <class T>
void Stack<T>::push(T x)
{
	head_ = new Node<T>(x, head_);
}

template <class T>
bool Stack<T>::empty()
{
	return head_ == NULL;
}

template <class T>
void Stack<T>::empty_stack()
{
	while (!empty())
	{
		pop();
	}
}

template <class T>
T Stack<T>::get()
{
	return top();
}

template <class T>
void Stack<T>::add(T x)
{
	push(x);
}

template <class T>
void Stack<T>::remove()
{
	pop();
}

template <class T>
void Stack<T>::empty_collection()
{
	empty_stack();
}
#endif
