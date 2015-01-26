#ifndef _NODE_H_
#define _NODE_H_

#include <cstddef>

template<class T>
class Node
{
	public:
		//constructors
		Node();
		Node(T d, Node<T> *n = NULL);

		//inspectors
		T get_data();
		Node<T> *get_next();

		//mutators
		void set_data(T d);
		void set_next(Node<T> *n);

	private:
		T data_;
		Node<T> *next_;
};

//constructors------------
template <class T>
Node<T>::Node()
{
	next_ = NULL;
}

template <class T>
Node<T>::Node(T d, Node<T> *n)
{
	data_ = d;
	next_ = n;
}
//------------------------
//inspectors--------------
template <class T>
T Node<T>::get_data()
{
	return data_;
}

template <class T>
Node<T> *Node<T>::get_next()
{
	return next_;
}
//------------------------
//mutators----------------
template <class T>
void Node<T>::set_data(T d)
{
	data_ = d;
}

template <class T>
void Node<T>::set_next(Node<T> *n)
{
	next_ = n;
}
//------------------------
#endif
