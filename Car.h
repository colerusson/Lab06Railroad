#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

struct Car {		//car struct that is used in the station class
	unsigned int id;
	Car() : id(0) {}		//the identifier of the car struct, which is a number
	Car(unsigned int id) : id(id) {}
	~Car() = default;

	bool operator==(const Car car) { return this->id == car.id; }
	bool operator!=(const Car car) { return this->id != car.id; }

	/** Return the Car as a string */
	string toString() {
		stringstream out;
		out << id;
		return out.str();
	} // end toString()

	  /** Make insertion operator friend for a Car */
	friend std::ostream& operator<< (ostream& os, Car& c) {
		os << c.toString();
		return os;
	} // end operator<<

};
#endif

