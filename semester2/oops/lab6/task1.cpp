/*Package Delivery Management System: You are tasked with developing a program for a package delivery
management system used by services like FedEx and DHL. The system should use inheritance and
polymorphism to calculate shipping costs for different types of packages.
(a) Define Classes Using Inheritance
Create a base class Package and derive the following two classes from it:
• TwoDayPackage: Represents packages with a two-day delivery option.
• OvernightPackage: Represents packages with an overnight delivery option.
(b) Implement the Base Class (Package)
The Package class should have:
• Attributes: Sender and recipient details (name, address, city, state, ZIP code), weight (double),
and costPerOunce (double).
• A constructor to initialize all attributes while ensuring positive values for weight and cost per ounce.
• A calculateCost() method that returns the shipping cost as weight × costPerOunce.
(c) Implement the Derived Classes
Each derived class must:
• Have additional attributes specific to their shipping method:
– TwoDayPackage: flatFee (double) for two-day delivery.
– OvernightPackage: extraFeePerOunce (double) for overnight shipping.
• A constructor that initializes both inherited and new attributes.
• A calculateCost() method that overrides the base class function:
– TwoDayPackage: Returns Package::calculateCost() + flatFee.
– OvernightPackage: Returns weight × (costPerOunce + extraFeePerOunce).
(d) Implement the main() Function
• Create an array of Package* objects (standard, two-day, and overnight).
• Use polymorphism to call calculateCost() dynamically.
• Display sender/recipient details and the total shipping cost for each package.
Your program should prompt the user to enter package details, choose a shipping option, and display
the calculated cost on runtime*/
#include<iostream>
#include<vector>
#include<string >
using namespace std;
class  package
{
protected:
    string name, address,city,state;
    int zip_code;
    double weigth;
    double costperounce;
public:
    package(string name, string address, string city, string state, int zip_code, double weigth, double costperounce)
    {
        this->name = name;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip_code = zip_code;
        this->weigth = (weigth > 0) ? weigth : 0;
        this->costperounce = (costperounce > 0) ? costperounce : 0;
    }
    virtual double calculatecost()
    {
        return weigth * costperounce;
    }
    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "city: " << city << endl;
        cout << "state: " << state << endl;
        cout << "zip_code :" << zip_code << endl;
        cout << "The cost of shipping is " << calculatecost() << endl;
    }
    virtual~package(){}
};
class two_day_package :public package
{
    double flatfee;
public:
    two_day_package(string a, string b, string c, string d, int e, double f, double g, double flatfee) :package(a, b, c, d, e, f, g)
    {
        this->flatfee = flatfee;
    }
    double calculatecost()override
    {
        return package::calculatecost() + flatfee;
    }
    void display()override
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "city: " << city << endl;
        cout << "state: " << state << endl;
        cout << "zip_code :" << zip_code << endl;
        cout << "The cost of shipping is " << calculatecost() << endl;
    }

};
class overnigthpackage :public package
{
    double extrafeeperounce;
public:
    overnigthpackage(string a, string b, string c, string d, int e, double f, double g, double extrafeeperounce) :package(a, b, c, d, e, f, g)
    {
        this->extrafeeperounce = extrafeeperounce;
    }
    double calculatecost()override
    {
        return weigth * (costperounce + extrafeeperounce);
    }
    void display() override
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "city: " << city << endl;
        cout << "state: " << state << endl;
        cout << "zip_code :" << zip_code << endl;
        cout << "The cost of shipping is " << calculatecost() << endl;
    }
};
int main()
{
    vector<package*>packages;
    int n;
    cout << "Enter the number of packages " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, address, city, state;
        int zip_code, option;
        double weigth, costperounce;
        cout << "Packages " << i + 1 << endl;
        cout << "Enter name \n"; getline(cin, name);
        cout << "Enter address\n"; getline(cin, address);
        cout << "Enter city\n"; getline(cin, city);
        cout << "Enter state\n"; getline(cin, state);
        cout << "Enter zip \n"; cin >> zip_code;
        cout << "Weigth:\n"; cin >> weigth;
        cout << "Enter cost per ounce \n";cin>>costperounce;
        cout << "Enter Shipping:(1:standar,2:twodaypackage, 3:overnigth)]\n";
        cin >> option;
        if (option == 1)
        {
            packages.push_back(new package(name, address, city, state, zip_code, weigth, costperounce));

        }
        else if(option==2)
        {
            double flatfee;
            cout << "Enter the flate fee " << endl;
            cin >> flatfee;
            packages.push_back(new two_day_package(name, address, city, state, zip_code, weigth, costperounce, flatfee));
        }
        else if (option == 3)
        {
            double extrafeeperounce;
            cout << "Enter the value of extra fee per ounce " << endl;
            cin >>  extrafeeperounce;
            packages.push_back(new overnigthpackage(name, address, city, state, zip_code, weigth, costperounce,extrafeeperounce));
        }
        else
        {
            cout << "Invalid input " << endl;
        }
    }
        for (package* dis : packages)
        {
            dis->display();
            delete dis;
        }

    return 0;

}