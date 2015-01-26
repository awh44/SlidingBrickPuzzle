#ifndef _COLLECTION_H_
#define _COLLECTION_H_

template <class T>
class Collection
{
	public:
		virtual ~Collection() {};
		virtual T get() = 0;
		virtual void add(T x) = 0;
		virtual void remove() = 0;
		virtual bool empty() = 0;
		virtual void empty_collection() = 0;
};
#endif
