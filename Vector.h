#ifndef VECTOR_H
#define VECTOR_H
#include "Deque.h"
#include <string>
using namespace std;

template <typename T>
class Vector {
private:
	Deque<T> vector_;

public:		//vector class that represents the train, which wraps around the deque class and uses its functions down below
	Vector() {}
	~Vector() = default;

	void push_back(const T& value) { 
		vector_.push_back(value);
	}
	void pop_back(void) { 
		vector_.pop_back();
	}
	T& back(void) { 
		return vector_.back();
	}
	size_t size(void) { 
		return vector_.size();
	}
	T& at(size_t index) {
		return vector_.at(index);
	}
	string toString(void) { 
		return vector_.toString();
	}
};
#endif

