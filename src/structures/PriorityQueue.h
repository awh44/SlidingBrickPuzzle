#include <queue>
#include <vector>
#include "Collection.h"

template <class T, class C> 
class PriorityQueue : public Collection<T>
{
	public:
		T get();
		void add(T x);
		void remove();
		bool empty();
		void empty_collection();
		bool contains(T x, bool (*comp)(T a, T b));
	private:
		std::priority_queue<T, std::vector<T>, C> queue_;
};

template <class T, class C>
void PriorityQueue<T, C>::add(T x)
{
	queue_.push(x);
}

template <class T, class C>
T PriorityQueue<T, C>::get()
{
	return queue_.top();
}

template <class T, class C>
void PriorityQueue<T, C>::remove()
{
	queue_.pop();
}

template <class T, class C>
bool PriorityQueue<T, C>::empty()
{
	return queue_.empty();
}

template <class T, class C>
void PriorityQueue<T, C>::empty_collection()
{
	while (!empty())
	{
		queue_.pop();
	}
}

/*
   DO NOT USE
*/
template <class T, class C>
bool PriorityQueue<T, C>::contains(T x, bool (*comp)(T a, T b))
{
	return true;
}
