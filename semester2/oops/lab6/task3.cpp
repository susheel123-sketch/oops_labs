/*Smart Home Appliance Management System: You are tasked with developing a Smart Home Appliance
Management System that monitors and controls different types of home appliances. The system should
allow efficient memory management and ensure that every appliance implements essential functionalities
while enforcing a common interface.
(a) Define Classes Using Inheritance
Create a base class Appliance and derive the following two classes from it:
• SmartLight: Represents a smart light that can be turned on/off and adjusted for brightness.
• SmartThermostat: Represents a smart thermostat that can regulate temperature.
(b) Implement the Base Class (Appliance)
The Appliance class should have:
• Attributes: brand (string), model (string), and powerStatus (bool) to track whether the appliance is on or off.
• A constructor to initialize these attributes.
• A turnOn() and turnOff() method to control power.
• A pure virtual function displayStatus() that must be implemented by all derived classes.
• A virtual destructor.
(c) Implement the Derived Classes
Each derived class must:
• SmartLight:
– Additional attribute: brightnessLevel (int) to adjust brightness.
– Implements displayStatus() to show power and brightness level.
• SmartThermostat:
– Additional attribute: temperature (double) to regulate room temperature.
– Implements displayStatus() to show power and temperature setting.
(d) Implement the main() Function
• Create an array of Appliance* objects, storing different appliance types dynamically.
• Use polymorphism to call displayStatus() dynamically for each appliance.
• Ensure proper memory management when deleting appliances.
Your program should allow the creation of different smart appliances, control their power status, and
display their unique settings while ensuring safe memory management.
*/
#include<iostream>
#include<string>
#include<limits>
using namespace std;
class appliance
{
    protected:
 string brand,model;
 bool powerstatus;
 public:
 appliance(string brand, string model,bool ps)
 {
    this->brand = brand;
    this->model = model;
    powerstatus = ps;
 } 
 void  turnon()
 {
    powerstatus =  true;
 }
 void turnoff()
{
    powerstatus= false;
}
virtual void display_ligth()
{
    cout<<"The Appliance "<<brand<<" of modal ";
    if(powerstatus)
    {
        cout<<" is ON"<<endl;
    }else
    {
        cout<<"is OFF"<<endl;
    }
}
virtual ~appliance(){}
};
class smartlight:public appliance
{
    int brightlevel;
    public:
    smartlight(string a, string b, bool c, int d):appliance(a, b,c)
    {
      brightlevel = d;
    }
 void display_ligth() override
{
    cout<<"The Appliance "<<brand<<" of modal is ";
    if(powerstatus)
    {
        cout<<" is open"<<endl;
    }else
    {
        cout<<"Not opened "<<endl;
    }
    cout<<"Brightness is "<<brightlevel<<"%"<<endl;
}
~smartlight(){}
};
class smartthermostat:public appliance
{
    double temperature;
    public:
    smartthermostat(string a, string b, bool c, double d):appliance(a,b,c)
    {
        temperature = d;
    }
void display_ligth() override
{
    cout<<"The Appliance "<<brand<<" of modal is ";
    if(powerstatus)
    {
        cout<<" is open"<<endl;
    }else
    {
        cout<<"Not opened "<<endl;
    }
    cout<<"Temperatur is "<<temperature<<endl;
}
};
int main()
{
    int n;
    cout<<"Enter No of appliance "<<endl;
    cin>>n;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    appliance**app  = new appliance*[n];
    for(int i =0;i<n;i++)
    {
        string brand, model;
        int power_status;
        int option;
        cout<<"Appliance "<<i+1<<endl;
        cout<<"Brand_Name;";
        getline(cin,brand);
        
        cout<<"Model:";
        getline(cin,model);
        
        cout<<"Turn?(1 for ON and 0 for Off ) "<<endl;
        cin>>power_status;
       
        cout<<"Enter the applaince:(1:Smart_light,2:Smart_Thermostat)"<<endl;
        cin>>option;
        if(option==1)
        {
            int brightlevel;
            cout<<"Enter the brigtness level of Smartlight "<<endl;
            cin>>brightlevel;
            app[i] = (new smartlight(brand,model,power_status,brightlevel));
        }
        else if(option ==2)
        {
            double temperature;
            cout<<"Enter Temperature of smart_thermostat"<<endl;
            cin>>temperature;
            app[i]=new smartthermostat(brand,model,power_status,temperature);
        }
        else
        {
            cout<<"Invalid option "<<endl;
            app[i] = nullptr;
        }

    }
    cout<<"------------------------------"<<endl;
    for(int i = 0;i<n;i++)
    {
        if(app[i])
        {
            app[i]->display_ligth();
            delete app[i];
        }
    }
    delete []app;
    return 0;
}