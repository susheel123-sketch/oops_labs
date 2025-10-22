/*Enterprise Payroll Management System: You are tasked with developing a program for an Enterprise
Payroll Management System that categorizes employees based on their job roles using multilevel inheritance and run-time polymorphism. The system should dynamically compute salaries while ensuring
proper class hierarchy and function overriding for structured employee information display.
(a) Define Classes Using Inheritance
Create a base class Person and derive the following two classes from it:
• Employee: Represents a general employee with a salary and experience.
• JobRole: Represents specific job roles and modifies salary calculations based on the role.
(b) Implement the Base Class (Person)
The Person class should have:
• Attributes: name (string), personID (int), and age (int).
• A constructor to initialize these attributes.
• A displayInfo() method declared as virtual for function overriding.
(c) Implement the Derived Classes
Each derived class must:
• Employee (inherits from Person):
– Attributes: baseSalary (double), yearsOfExperience (int), and department (string).
– Implements calculateSalary(): Adjusts salary based on experience.
– Overrides displayInfo() to include employee details.
• JobRole (inherits from Employee):
– Attributes: jobTitle (string).
– Overrides calculateSalary() to adjust salary based on job type (Salaried or Hourly).
– Overrides displayInfo() to include job role details.
(d) Implement the main() Function
• Create an array of JobRole* objects, each representing an employee with a different role.
• Use run-time polymorphism to dynamically call calculateSalary() and displayInfo().
• Display each employee’s structured details and final salary.
Your program should initialize employee data, categorize them into different job roles, and compute their
salaries dynamically based on experience and job type.
*/
#include<iostream>
#include<string>
using namespace std;
class person
{
  string name;
  int person_id, age;
  public:
  person(string name, int id, int age )
  {
    this->name = name;
    person_id= id;
    this->age = age;
  }
  virtual void display_info()
  {
    cout<<"Name :"<<name<<endl;
    cout<<"Personal Id :"<<person_id<<endl;
    cout<<"Age is : "<<age<<endl;
  }
};
class employe:public person
{
  double base_salary;
  int yearof_experience;
  string department;
  public:
  employe(string a, int b, int c, double d, int e, string f):person(a,b,c)
  {
    base_salary = d;
    yearof_experience = e;
    department = f;
  }
  virtual int calculate_salary()
  {
    int current_salary = 0;
    if(yearof_experience>0&&yearof_experience<=5){
       current_salary = base_salary*(1+5*0.01);
    }else if(yearof_experience>5&&yearof_experience<=10)
    {
        current_salary = base_salary*(1+10*0.01);
    }else if(yearof_experience>10&&yearof_experience<=15)
    {
        current_salary = base_salary*(1+15*0.01);
    }
    else if(yearof_experience>15)
    {
        current_salary = base_salary*(1+20*0.01);
    }
    return current_salary;
}
  void display_info() override
  {
    person::display_info();
    cout<<"Base salary is "<<base_salary<<endl;
    cout<<"Year of experience "<<yearof_experience<<endl;
    cout<<"Department is  "<<department<<endl;
  }
};
class job_role:public employe
{
   string job_title;
   public:
   job_role(string a, int b, int c, double d, int e, string f, string job):employe(a, b,c,d,e, f)
   {
    job_title = job;
   }
  int calculate_salary()
  {
    int salary = employe::calculate_salary();
    if(job_title == "salaried")
    {
      salary+=2000;
    }else if(job_title == "Hourly")
    {
      salary+=1000;
    }
    return salary;

  } 
  void display_info()override
  {
    employe::display_info();
    cout<<"Job title is "<<job_title<<endl;
    cout<<"Final salary is "<<calculate_salary()<<endl;
  }
};
int main()
{
  job_role*employes[3];
  employes[0] = new job_role("Ismail",1223,23,400000.0,5,"IT","salaried");
  employes[1] = new job_role("Ahmed",1003,34,1000000,15,"Finance","salaried");
  employes[2] = new job_role("Asad",3000,20,900000,10,"Intern","hourly");
  for(int i =0;i<3;i++)
{
  cout<<"------------------------"<<endl;
  employes[i]->display_info();
}
  for(int i = 0;i<3;i++)
  {
    delete employes[i];
  }
    return 0;
}