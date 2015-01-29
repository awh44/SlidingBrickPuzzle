#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cstddef>

#include "Collection.h"
#include "Node.h"

template <class T>
class Queue : public Collection<T>
{
	public:
		Queue();
		~Queue();
		T front();
		void enqueue(T x);
		void dequeue();
		bool empty();
		void empty_queue();

		T get();
		void add(T x);
		void remove();
		void empty_collection();
		bool contains(T x, bool (*comp)(T a, T b));

	private:
		Node<T> *front_;
		Node<T> *rear_;
};

template <class T>
Queue<T>::Queue()
{
	front_ = new Node<T>(T(), NULL);
	rear_ = front_;
}

template <class T>
Queue<T>::~Queue()
{
	empty_queue();
}

template <class T>
T Queue<T>::front()
{
	return front_->get_next()->get_data();	
}

template <class T>
void Queue<T>::enqueue(T x)
{
	Node<T> *n = new Node<T>(x, NULL);
	rear_->set_next(n);
	rear_ = n;
}

template <class T>
void Queue<T>::dequeue()
{
	Node<T> *temp = front_;
	front_ = front_->get_next();
	delete temp;
}

template <class T>
bool Queue<T>::empty()
{
	return front_ == rear_;
}

template <class T>
void Queue<T>::empty_queue()
{
	while (!empty())
	{
		dequeue();
	}
}

template <class T>
T Queue<T>::get()
{
	return front();
}

template <class T>
void Queue<T>::add(T x)
{
	enqueue(x);
}

template <class T>
void Queue<T>::remove()
{
	dequeue();
}

template <class T>
void Queue<T>::empty_collection()
{
	empty_queue();
}

template <class T>
bool Queue<T>::contains(T x, bool (*comp)(T a, T b))
{
	Node<T> *node = front_->get_next();
	while (node != NULL)
	{
		if (comp(x, node->get_data()))
		{
			return true;
		}

		node = node->get_next();
	}

	return false;
}
#endif
