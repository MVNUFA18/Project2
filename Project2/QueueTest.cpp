// QueueTest.cpp
// example "driver" program to test Queue class for Project 2
// Author: Bob Kasper
// Last Revised: 9/26/2018

#include "pch.h"
#include "Queue.h" // defines Queue class to be tested
#include <iostream>
using namespace std;

#define CAPACITY 10

int main () {
	Queue<int> myQueue(CAPACITY);

	// test adding to queue
	myQueue.enqueue(1);
	myQueue.enqueue(2);
	// test access functions
	cout << "front element of queue: " << myQueue.front() << endl;
	cout << "The queue size is " << myQueue.size() << endl;
	cout << "Is the queue emepty? " << (myQueue.empty() ? "Yes" : "No") << endl;

	// test removing from queue
	myQueue.dequeue();
	cout << "After removing one element, front is " << myQueue.front() << endl;
	// test wrap-around with circular array
	for (int i = 0; i <= CAPACITY; i++) {
		myQueue.enqueue(i);
		myQueue.dequeue();
	}
	cout << "After adding " << CAPACITY + 1 << " elements, front is "
		<< myQueue.front() << endl;
	myQueue.dequeue();
	cout << "The queue size is " << myQueue.size() << endl;
	cout << "Is the queue emepty? " << (myQueue.empty() ? "Yes" : "No") << endl;
	// An exception should be thrown here
	cout << "front of empty queue: (should throw an exception): "
		<< myQueue.front() << endl;
	// To test the following code, comment out previous front operation,
	// after verifying an exception is thrown
	cout << "dequeue from empty queue: (should also throw an exception): " << endl;
	myQueue.dequeue();

	// To test the following code, comment out previous dequeue operation
	cout << "add more than CAPACITY: (should also throw an exception): " << endl;
	for (int i = 0; i <= CAPACITY; i++) {
		myQueue.enqueue(i);
	}

	system("pause");
	return 0;
}
