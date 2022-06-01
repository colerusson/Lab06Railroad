#ifndef STACK_H
#define STACK_H
#include "Deque.h"
#include <string>
using namespace std;


template <typename T>
class Stack {
private:
	Deque<T> stack_;

public:		//stack class that represents the stack, which wraps around the deque class and uses its functions down below
	Stack() {}
	~Stack() = default;

	void push_back(const T& value) {
		stack_.push_back(value);
	}
	void pop_back(void) {
		stack_.pop_back();
	}
	T& back(void) {
		return stack_.back();
	}
	size_t size(void) {
		return stack_.size();
	}
	T& at(size_t index) { 
		return stack_.at(index);
	}
	string toString(void) { 
		return stack_.toString();
	}
};

#endif

