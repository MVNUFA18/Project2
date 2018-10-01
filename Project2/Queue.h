/* Queue.h
 * a circular array-based implementation of the Queue ADT.
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "RuntimeException.h"

class QueueEmpty : public RuntimeException {
public:
	QueueEmpty(const string& err) : RuntimeException(err) {}
};

class QueueFull : public RuntimeException {
public:
	QueueFull(const string& err) : RuntimeException(err) {}
};



template <typename E>
class Queue {
	enum { DEF_CAPACITY = 100 };			// default queue capacity
public:
	Queue(int cap = DEF_CAPACITY);		// constructor from capacity
	int size() const;						// number of items in the queue
	bool empty() const;						// is the queue empty?
	bool full() const;						// is the queue full?
	const E& front() const throw(QueueEmpty);	//the front element 
	void enqueue(const E& e) throw(QueueFull);	// enqueue element at rear
	void dequeue() throw(QueueEmpty);			// dequeue element at front
	// ...housekeeping functions
	~Queue() 							// destructor
	{
		delete[] Q;
	}
private:                        // member data
	E* Q;					    // array of queue elements
	int capacity;			    // queue capacity
	int queueFront;					// index of the front of the queue
	int queueRear;				    // index of the rear of the queue
	int sizeHolder;
};


/* member function definitions */

//template <typename E> // constructor from capacity
//Queue<E>::Queue(int cap)
//	: Q(new E[cap]), capacity(cap){ }

template <typename E>
Queue<E>::Queue(int cap) {
	capacity = cap;
	queueFront = queueRear = -1;
	sizeHolder = 0;
	Q = new E[capacity];
}


template <typename E> // push element to the back of the queue
void Queue<E>::enqueue(const E& e) {
	if (empty()) {
		queueFront = 0;
	}
	else if (full()) { throw QueueFull("Full queue"); }
	queueRear = (queueRear + 1) % capacity;
	Q[queueRear] = e;
	sizeHolder++;
}

template <typename E> // pop the front item of the queue
void Queue<E>::dequeue() throw(QueueEmpty) {
	if (empty()) throw QueueEmpty("Empty Queue");
	queueFront = (queueFront + 1) % capacity;
	sizeHolder--;
}

template <typename E> // return back of the queue
const E& Queue<E>::front() const throw(QueueEmpty) {
	if (empty()) throw QueueEmpty("Empty Queue");
	return Q[queueFront];
}

template <typename E> // number of items in the queue
int Queue<E>::size() const
{
	return sizeHolder;
}

template <typename E> // is the queue empty?
bool Queue<E>::empty() const
{
	return (size() == 0);
}

template <typename E> // is the queue full?
bool Queue<E>::full() const 
{
	return ( (queueRear + 1) % capacity) == queueFront;
}

#endif