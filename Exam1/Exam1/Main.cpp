/*I affirm that all code given below was written solely by me, Nicholas Little,
and that any help I received adhered to the rules stated for this exam.*/

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		Wheel(int radius) { _radius = radius; }
	};

	// STEP 1: Complete the implementation of the Vehicle base class 
	// as described in the UML diagram
	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		vector<Wheel> wheels;

	public:
		Vehicle() {};
		Vehicle(string color) {
			// Complete the implementation
			_color = color; //set inital color for Vehicle
		}
		virtual void Description() = 0;
	};

	// STEP 2:  Define the RaceCar, Sedan, and Pickup classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.
	class RaceCar : public Vehicle {
		//Top speed: 250mph
		//Wheel radius: 305mm
	public:
		RaceCar(string color) {
			_color = color;//set inital color for RaceCar
			_topspeed = 250;//set top speed for RaceCar
			wheels.assign(4, Wheel(305));//assign 4 wheels with radius 305mm
		}
		void Description() {
			cout << "I am a speedy race car that can go " << _topspeed << ". Just try to keep up!" << endl;//over confident race car description
		}
	};

	class Sedan : public Vehicle {
		//Top speed: 95mph
		//Wheel radius: 381mm
	protected:
		int number_of_seats;
	public:
		Sedan(string color, int seats) {
			_color = color;//set inital color for Sedan
			_topspeed = 95;//set top speed for Sedan
			number_of_seats = seats;//set number of seats for Sedan
			wheels.assign(4, Wheel(381));//assign 4 wheels with radius 381mm
		}
		void Description() {
			cout << "I am a practical sedan that can carry " << number_of_seats << " people at a good pace of " << _topspeed <<". How practical!"<< endl;//description of non descript sedan
		}
	};

	class Pickup : public Vehicle{
		//Top speed: 85mph
		//Wheel radius: 432mm
	protected:
		int hauling_capacity;//sq. ft of bed of truck
	public:
		Pickup(string color, int maxCap) {
			_color = color;//set initial color for Pickup
			_topspeed = 85;//set top speed for Pickup
			hauling_capacity = maxCap;//set hauling capacity for Pickup
			wheels.assign(4, Wheel(432));//assign 4 wheels with radius 432mm
		}
		void Description() {
			cout << "I am a hard working truck that can carry " << hauling_capacity << " sq. feet of anything and get you there at a speed of " << _topspeed << ". Hey thats not bad for the work I'm doing." << endl;//a solid description of a pickup
		}

	};
}


int main()
{
	Exam1::Vehicle * Garage[3];

	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements 
	// in the Garage array.  Remember the classes are defined in the namespace Exam1.
	Garage[0] = &Exam1::RaceCar("red");
	Garage[1] = &Exam1::Pickup("black", 500);
	Garage[2] = &Exam1::Sedan("blue", 5);
	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like 
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();
	}
}
