/*Vehicle Control System: You are developing a system to manage different types of vehicles. The system has a base class Vehicle and two derived classes: Car and Bike. Each vehicle has a method
void start() that prints the type of vehicle being started. Additionally, Car has a method void
setSpeed(double speed) to set its speed.
Task:
• Create a base class Vehicle with a virtual method void start() that prints "Starting a
vehicle.".
• Create two derived classes:
– Car: Overrides start() to print "Starting a car." and adds a method void setSpeed(double
speed) that prints "Car speed set to <speed> km/h.".
– Bike: Overrides start() to print "Starting a bike.".
Implementation in main():
• Create a Car object and a Bike object.
• Store them in a vector<Vehicle*> of pointers.
• Iterate through the vector and call start() for each vehicle.
• For cars only, call setSpeed(). (Hint: You’ll need to determine if a Vehicle* pointer actually
points to a Car object.)
*/
#include <iostream>
#include <vector>
using namespace std;
class Vehicle 
{
public:
    virtual void start() 
    {
        cout << "Starting a vehicle." << endl;
    }
};
class Car : public Vehicle 
{
public:
    void start() override
    {
        cout << "Starting a car." << endl;
    }

    void setSpeed(double speed) 
    {
        cout << "Car speed set to " << speed << " km/h." << endl;
    }
};
class Bike : public Vehicle {
public:
    void start() override {
        cout << "Starting a bike." << endl;
    }
};
int main() {
    Car car;
    Bike bike;
    vector<Vehicle*> vehicles;
    vehicles.push_back(&car);
    vehicles.push_back(&bike);

    for (Vehicle* v : vehicles) {
        v->start();
        Car* carPtr = dynamic_cast<Car*>(v);
        if (carPtr) {
            carPtr->setSpeed(120.0); 
        }
    }

    return 0;
}
