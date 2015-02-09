#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <iostream>

#include "Node.h"

template <class T>
class Dictionary
{
	public:
		Dictionary(size_t (*hash)(T x), bool (*compare)(T a, T b));
		Dictionary(size_t num_buckets, size_t (*hash)(T x), bool (*compare)(T a, T b));
		~Dictionary();
		void insert(T x);
		void delete_member(T x);
		bool member(T x);
		void empty_dictionary();
#ifdef __DEBUGGING__
		//method for testing
		void print_dict();
#endif

	private:
		size_t hash(T x);

		static const size_t DEFAULT_BUCKETS = 10;

		size_t (*hash_)(T x);
		bool (*compare_)(T a, T b);
		Node<T> **buckets_;
		size_t num_buckets_;
};

template <class T>
Dictionary<T>::Dictionary(size_t (*hash)(T x), bool (*compare)(T a, T b))
	: Dictionary(DEFAULT_BUCKETS, hash, compare)
{
}

template <class T>
Dictionary<T>::Dictionary(size_t num_buckets, size_t (*hash)(T x), bool (*compare)(T a, T b))
{
	buckets_ = new Node<T>*[num_buckets]();
	num_buckets_ = num_buckets;
	hash_ = hash;
	compare_ = compare;
}

template <class T>
Dictionary<T>::~Dictionary()
{
	empty_dictionary();
	delete[] buckets_;
}

template <class T>
void Dictionary<T>::insert(T x)
{
	//if (!member(x))
	{
		size_t hash_value = hash(x);
		Node<T> *n = new Node<T>(x, buckets_[hash_value]);
		buckets_[hash_value] = n;
	}
}

template <class T>
void Dictionary<T>::delete_member(T x)
{
	size_t hash_value = hash(x);
	if (buckets_[hash_value])
	{
		//case where the header points to the Node with the value
		if (compare_(buckets_[hash_value]->get_data(), x))
		{
			Node<T> *temp = buckets_[hash_value];
			buckets_[hash_value] = buckets_[hash_value]->get_next();
			delete temp;
		}
		else
		{
			//otherwise look for that value in the rest of the list
			Node<T> *p = buckets_[hash_value];
			while (p->get_next() != NULL)
			{
				if (compare_(p->get_next()->get_data(), x))
				{
					Node<T> *temp = p->get_next();
					p->set_next(temp->get_next());
					delete temp;
					return;
				}
				p = p->get_next();
			}
		}
	}
}

template <class T>
void Dictionary<T>::empty_dictionary()
{
	for (size_t i = 0; i < num_buckets_; i++)
	{
		Node<T> *tmp = buckets_[i];
		while (tmp != NULL)
		{
			buckets_[i] = tmp->get_next();
			delete tmp;
			tmp = buckets_[i];
		}
	}
}

template <class T>
bool Dictionary<T>::member(T x)
{
	size_t hash_value = hash(x);
	Node<T> *p = buckets_[hash_value];
	while (p != NULL)
	{
		if (compare_(p->get_data(), x))
			return true;
		p = p->get_next();
	}

	return false;
}

#ifdef __DEBUGGING__
template <class T>
void Dictionary<T>::print_dict()
{
	for (size_t i = 0; i < num_buckets_; i++)
	{
		std::cout << "Contents of bucket_[" << i << "]: ";
		Node<T> *p = buckets_[i];
		while (p != NULL)
		{
			std::cout << (*p).get_data() << " ";
			p = (*p).get_next();
		}
		std::cout << std::endl;
	}
}
#endif

template <class T>
size_t Dictionary<T>::hash(T x)
{
	return hash_(x) % num_buckets_;
}

#endif
