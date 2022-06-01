#ifndef QUEUE_H
#define QUEUE_H
#include "Deque.h"
#include <string>
using namespace std;


template <typename T>
class Queue {
private:
	Deque<T> queue_;

public:		//queue class that represents the queue, which wraps around the deque class and uses its functions down below
	Queue() {}
	~Queue() = default;

	void push_back(const T& value) {
		queue_.push_back(value);
	}
	void pop_front(void) {
		queue_.pop_front();
	}
	T& top(void) {
		return queue_.front();
	}
	size_t size(void) {
		return queue_.size();
	}
	T& at(size_t index) { 
		return queue_.at(index);
	}
	string toString(void) { 
		return queue_.toString();
	}
};
#endif

