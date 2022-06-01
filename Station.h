#ifndef STATION_H
#define STATION_H
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"
#include <string>
using namespace std;

template <typename T>
class Station {
private:
	Vector<T> train_;
	Stack<T> stack_;
	Queue<T> queue_;
	T turnTableCar_;
	bool empty = true;

public:
	Station() {}
	~Station() = default;

	string addCar(const T& car) {		//addcar function to put a car on the turntable, setting it equal to car
		if (empty == false) {
			return string(" Turntable occupied!");
		}
		else {
			turnTableCar_ = car;
			empty = false;
			return string(" OK");
		}
	}
	string removeCar() {		//remove car function that pushes the the turntable car into the train vector 
		if (empty == true) {
			return string(" Turntable empty!");
		}
		else {
			train_.push_back(turnTableCar_);
			empty = true;
			return string(" OK");
		} 
	}
	string topCar() {		//returns the car that is on the turntable
		if (empty == true) {
			return string(" Turntable empty!");
		}
		else {
			return turnTableCar_.toString();
		}
	}
	string sizeTrain() {		//returns the size of the train vector, calling to the vector class
		stringstream out;
		out << " " << train_.size();
		return out.str();
	}
	string addStack() {			//moves the car on the turntable into the stack, calling pushback of stack class
		if (empty == true) {
			return string(" Turntable empty!");
		}
		else {
			stack_.push_back(turnTableCar_);
			empty = true;
			return string(" OK");
		}
	}
	string removeStack() {		//moves a car from the stack back onto the turntable
		if (empty == false) {
			return string(" Turntable occupied!");
		}
		else {
			if (stack_.size() == 0) {
				return string(" Stack empty!");
			}
			else {
				turnTableCar_ = stack_.back();
				stack_.pop_back();
				empty = false;
				return string(" OK");
			}
		}
	}
	string topStack() {			//returns the top item of the stack
		return stack_.back().toString();
	}
	string sizeStack() {
		stringstream out;
		out << " " << stack_.size();
		return out.str();
	}
	string addQueue() {			//moves a car from the turntable into the queue 
		if (empty == true) {
			return string(" Turntable empty!");
		}
		else {
			queue_.push_back(turnTableCar_);
			empty = true;
			return string(" OK");
		}
	}
	string removeQueue() {		//moves a car from the queue back onto the turntable
		if (empty == false) {
			return string(" Turntable occupied!");
		}
		else {
			if (queue_.size() == 0) {
				return string(" Queue empty!");
			}
			else {
				turnTableCar_ = queue_.top();
				queue_.pop_front();
				empty = false;
				return string(" OK");
			}
		}
	}
	string topQueue() {			//returns the car at the top of the queue
		return queue_.top().toString();
	}
	string sizeQueue() {		//returns the current size of the queue
		stringstream out;
		out << " " << queue_.size();
		return out.str();
	}
	string find(T car) {		//find's an item in the train, queue, or stack and returns the location
		stringstream out;
		for (int i = 0; i < train_.size(); ++i) {
			if (train_.at(i) == car) {
				out << " Train[" << i << "]";
				return out.str();
			}
		}
		for (int i = 0; i < queue_.size(); ++i) {
			if (queue_.at(i) == car) {
				out << " Queue[" << i << "]";
				return out.str();
			}
		}
		for (int i = 0; i < stack_.size(); ++i) {
			if (stack_.at(i) == car) {
				out << " Stack[" << i << "]";
				return out.str();
			}
		}
		return string(" Not Found!");
	}

	string vectorToString() { return train_.toString(); }		//to string functions for the train, queue, and stack
	string queueToString() { return queue_.toString(); }
	string stackToString() { return stack_.toString(); }
};
#endif

