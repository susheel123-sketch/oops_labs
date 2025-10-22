/*Vehicle Management System: Develop a Vehicle Management System that manages different types
of vehicles, allowing users to store and retrieve details about cars, bikes, and trucks.
(a) Define Classes Using Inheritance
Create a base class Vehicle and derive the following three classes from it:
• Car: Represents passenger cars.
• Bike: Represents motorbikes or scooters.
• Truck: Represents heavy-duty trucks.
(b) Implement the Base Class (Vehicle)
The Vehicle class should have:
• Attributes: brand (string), model (string), and yearManufactured (int).
• A constructor to initialize all attributes.
• A printDetails() method that prints all vehicle details.
(c) Implement the Derived Classes
Each derived class must:
• Have 2–3 additional attributes:
– Car: numDoors (int), fuelType (string).
– Bike: engineCC (int), hasABS (bool).
– Truck: payloadCapacity (double), numAxles (int).
• A constructor that initializes both inherited and new attributes.
• A printDetails() method that prints all attributes, including inherited ones.
(d) Implement the main() Function
• Create at least 5 instances of each derived class (Car, Bike, Truck).
• Store them in an array of pointers to the base class (Vehicle*).
• Iterate through the array and call the printDetails() method for each object*/
#include<iostream>
#include<string>
using namespace std;
class vehicle{
    protected:
    string brand;
    string modal;
    int year_manufactured;
    public:
    vehicle(string a, string b, int c){
        brand = a;
        modal = b;
        year_manufactured = c;
    }
    virtual void print_details(){
        cout<<"Modal:"<<modal<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Year Manufactured: "<<year_manufactured<<endl;
    }
};
class car:public vehicle
{
    int Numdoor;
    string Fuel_type;
    public:
    car(string a, string b, int c, int d, string e ):vehicle(a,b,c){
        Numdoor = d;
        Fuel_type = e;
}
    void print_details() override{
        cout<<"Modal:"<<modal<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Year Manufactured: "<<year_manufactured<<endl;
        cout<<"Number of doors "<<Numdoor<<endl;
        cout<<"Fuel type "<<Fuel_type<<endl;
    }
 
};
class bike:public vehicle
{
    int engineCC;
    bool hasABS;
    public:
    bike(string a, string b, int c, int d, bool e):vehicle(a,b,c){
        engineCC = d;
        hasABS = e;
    }
     void print_details()override{
        cout<<"Modal:"<<modal<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Year Manufactured: "<<year_manufactured<<endl;
        cout<<"Engine :"<<engineCC<<endl;
        cout<<"HasABS "<<hasABS<<endl;
    }
 
};
class truck:public vehicle
{
    double pay_load_capacity;
    int num_axle;
    public:
    truck(string a, string b, int c, double d, int e):vehicle(a,b,c){
        pay_load_capacity = d;
        num_axle = e;
    }
     void print_details() override {
        cout<<"Modal:"<<modal<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Year Manufactured: "<<year_manufactured<<endl;
        cout<<"Pay load capacity  "<<pay_load_capacity<<endl;
        cout<<"NUm axle  "<<num_axle<<endl;
    }
    
 
};
int main(){

    car c1("Honda", "Civic", 2022, 4, "Petrol");
    car c2("Toyota", "Corolla", 2020, 4, "Hybrid");
    car c3("Suzuki", "Alto", 2021, 4, "Petrol");
    car c4("Kia", "Sportage", 2019, 4, "Diesel");
    car c5("Hyundai", "Elantra", 2023, 4, "Petrol");

    bike b1("Yamaha", "YBR", 2018, 125, true);
    bike b2("Honda", "CG125", 2019, 125, false);
    bike b3("Suzuki", "GS150", 2020, 150, true);
    bike b4("Kawasaki", "Ninja", 2021, 400, true);
    bike b5("BMW", "G310R", 2022, 313, true);

    truck t1("Volvo", "FH16", 2015, 20.5, 6);
    truck t2("Scania", "R500", 2016, 25.0, 8);
    truck t3("Mercedes", "Actros", 2017, 18.0, 6);
    truck t4("MAN", "TGX", 2018, 30.0, 10);
    truck t5("Hino", "500", 2019, 15.0, 4);
    vehicle*vec[15] = { &c1, &c2, &c3, &c4, &c5,
                      &b1, &b2, &b3, &b4, &b5,
                       &t1, &t2, &t3, &t4, &t5 };

    for(int i =0;i<15;i++){
        cout<<"--------------------"<<endl;
        vec[i]->print_details();
    }
    
    return 0;
}