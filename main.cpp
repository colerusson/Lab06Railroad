#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include "Car.h"
#include "Station.h"

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif		

int main(int argc, char* argv[]) {
	VS_MEM_CHECK	//implementing memory check

		if (argc < 3) {
			cerr << "Please provide name of input and output files";
			return 1;
		}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	Station<Car>* station = new Station<Car>();
	for (string line; getline(in, line);) {
		if (line.size() == 0) continue;
		out << line;
		istringstream iss(line);
		string line1;
		unsigned int id;
		iss >> line1;
		try {
			if (line1 == "Add:station") { 
				//Add a car to the station turntable
				iss >> id;
				out << station->addCar(Car(id));
			}
			else if (line1 == "Add:stack") {
				//Add the car on turntable to the stack roundhouse
				out << station->addStack();
			}
			else if (line1 == "Add:queue") {
				//Add the car on turntable to the queue roundhouse
				out << station->addQueue();
			}
			else if (line1 == "Remove:station") {
				//Moves the car on the station turntable to the train vector 
				out << station->removeCar();
			}
			else if (line1 == "Remove:stack") {
				//Moves a car in the stack roundhouse back to the station turntable
				out << station->removeStack();
			}
			else if (line1 == "Remove:queue") {
				//Moves a car in the queue roundhouse back to the station turntable 
				out << station->removeQueue();
			}
			else if (line1 == "Top:station") {
				//Displays the current car on top of the station turntable  
				out << station->topCar();
			}
			else if (line1 == "Top:stack") {
				//Display the train car at head of stack roundhouse
				out << " " << station->topStack();
			}
			else if (line1 == "Top:queue") {
				//Display the train car at head of queue roundhouse
				out << " " << station->topQueue();
			}
			else if (line1 == "Size:stack") {
				//Output number of train cars in stack 
				out << station->sizeStack();
			}
			else if (line1 == "Size:queue") {
				//Output number of train cars in queue 
				out << station->sizeQueue();
			}
			else if (line1 == "Size:train") {
				//Output number of train cars in the train vector
				out << station->sizeTrain();
			}
			else if (line1 == "Find") {
				//Find and display the current location and position of a car in the station data structures (turntable, queue, stack, or vector)
				iss >> id;
				out << station->find(Car(id));
			}
			else if (line1 == "Queue") {
				//Display the contents of the station queue roundhouse
				out << station->queueToString();
			}
			else if (line1 == "Stack") {
				//Display the contents of the station stack roundhouse
				out << station->stackToString();
			}
			else if (line1 == "Train") {
				//Display the contents of the train vector
				out << station->vectorToString();
			}
			else {
				out << "????? " << "[" << line << "]";
			}
		}
		catch (exception& e) { out << e.what(); }
		out << endl;
	}
	
	delete station;		//deallocate the memory of the station class to prevent memory leaks 
	in.close();

	return 0;
}
